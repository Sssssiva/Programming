import confixg  # Импорт config.py
import urllib.request  # request нужен для загрузки файлов от пользователя
import requests 
from telebot import types, TeleBot
import http
import json
import uuid#для сессии
from glob import glob#для картинок список из названий картинок
from random import choice 
bot = TeleBot('1783668752:AAFZm5madviWRh7mCgjuNB3ektsnzCGS4cg')  # Передаём токен из файла config.py


users = []  # Тут храним данные о пользователях

def send_photo(message,money):
    lists=glob('images/*')
    picture=choice(lists)
    bot.send_photo(chat_id=message.chat.id,caption=f"*Абсолютно верно! Ты зарабатываешь {money}$. Так держать!*",photo=open(picture,'rb'),parse_mode="Markdown")

def get_user(user_id):
    for x in range(len(users)):  # Проходим через массив
        if users[x]['id'] == user_id:  # Ищем в массиве пользователя с определенным id
            return users[x]  # возвращаем пользователя из массива

    return None  # если пользователя с таким id нет в массиве


def add_user(user_id):
    # Создаем объект
    user = {
        'id': user_id,
        'money': 0,
        'question': 1,  # номер вопроса, на который пользователь дожен ответить
        'session': 0,
        'Is_playing':False
    }

    users.append(user)  # добавляем его в массив

    return user

@bot.message_handler(commands=['stop'])
def end(message):

    
    user_id = message.chat.id
    user=get_user(user_id)
    if user is None:  # если пользователя нет в массиве, значит его нужно добавить
        user = add_user(user_id)
    teg=user['Is_playing']
    if(teg==True):
        name=message.chat.first_name
        session=user["session"] 
        payload = {'id': str(user_id), 'name': str(name),'money': str(user['money'])}
        requests.post('http://localhost:5000/top',data=payload) 
        requests.post('http://localhost:5000/delete',data=session)

        message = bot.send_message(message.chat.id,
                                           f"Ты заработал {user['money']}$, а мог бы больше. Быстро однако ты сдаешься...")
        user['money'] = 0
        user['question'] = 1
        user['session']=0
        user['Is_playing']=False
    else:
        bot.send_message(message.chat.id,
                                           "Ты еще даже не начал играть...")


    

@bot.message_handler(commands=['start'])
def welcome_start(message):

    first_message = types.ReplyKeyboardMarkup(row_width=3, resize_keyboard=True,one_time_keyboard=True) 
    button1 = types.KeyboardButton("/help")
    button2 = types.KeyboardButton("Рейтинг")
    button3 = types.KeyboardButton("/game")

    first_message.add(button1, button2, button3)

    bot.send_message(message.chat.id,
                     "Добро пожаловать, *{0.first_name}*!\nЯ - *{1.first_name}*, бот  созданный для того, чтобы оценить ваши знания в денежном эквиваленте. ".format(
                      message.from_user, bot.get_me()), parse_mode="Markdown", reply_markup=first_message)
    
   

@bot.message_handler(commands=['game'])
def play(message):

    user_id = message.chat.id # из сообщения вытаскиваем id пользователя
    user = get_user(user_id)

    if user is None:  # если пользователя нет в массиве, значит его нужно добавить
        user = add_user(user_id)

    n = user['question'] # получаем номер вопроса на который пользователь должен ответить
   
    if user['session'] == 0:
        user['session']=(str(uuid.uuid4()))[:16] #Сессия пользователя

    session=user['session']
    user['Is_playing']=True
    datagame={"session":session,"question":user["question"]}

    data_server= requests.post('http://localhost:5000/get_q',data=datagame)

    info_que=json.loads(data_server.text)

    title=info_que["question"]
    answers=info_que["answers"]

    def format_data(correct: bool):
        return json.dumps({'correct': correct, 'c_q': n,'session': session})

   
    answer = types.InlineKeyboardMarkup(row_width=1)
    but1 = types.InlineKeyboardButton(answers[0]["text"], callback_data=format_data(answers[0]["isCorrect"]))
    but2 = types.InlineKeyboardButton(answers[1]["text"], callback_data=format_data(answers[1]["isCorrect"]))
    but3 = types.InlineKeyboardButton(answers[2]["text"], callback_data=format_data(answers[2]["isCorrect"]))
    but4 = types.InlineKeyboardButton(answers[3]["text"], callback_data=format_data(answers[3]["isCorrect"]))
    answer.add(but1, but2, but3, but4)

    bot.send_message(message.chat.id, text=f" Вопрос номер {n}.\n{title}", reply_markup=answer)



@bot.callback_query_handler(func=lambda call: True)
def callback_inline(call):
    try:
        if call.message:
            user_id = call.message.chat.id
            user = get_user(user_id)
            data=json.loads(call.data)
            correct=data['correct']
            current_question=data['c_q']
                
            session=data['session']
            name=call.message.chat.first_name
            if correct:
                if user['session'] != session:
                    pass
                elif current_question != user['question']:
                    pass
                # добавим пользователю денег
                elif user:
                    if (current_question<=10):#первый этап
                        user['money'] += 50
                        user['question'] += 1

                    if (current_question>10 and current_question<=20):#второй этап
                        user['money'] += 100
                        user['question'] += 1

                    if (current_question>20):#третий этап
                        user['money'] += 200
                        user['question'] += 1

                    send_photo(call.message,user['money'])
                    if(current_question==10):
                        bot.send_message(call.message.chat.id, "*ПОЗДРАВЛЯЮ!* Ты переходишь на второй *этап*. Теперь вопросы станут на порядок *сложнее*, но зато количество денег за правильный ответ *увеличится* до 100$",parse_mode="Markdown")
                    if( current_question==20):
                        bot.send_message(call.message.chat.id, "*ПОЗДРАВЛЯЮ!* Ты переходишь на третий, самый сложный *этап*. Теперь вопросы станут невероятно *сложными*, но зато количество денег за правильный ответ *увеличится* до 200$",parse_mode="Markdown")
                    play(call.message)

            elif not correct :
            
                if user['session'] != session:
                    pass
           
                elif current_question != user['question']:
                    pass
                    
                elif user:
                    payload = {'id': str(user_id), 'name': str(name),'money': str(user['money']),}
                    requests.post('http://localhost:5000/delete',data=session)
                    requests.post('http://localhost:5000/top',data=payload) 
                    bot.send_message(call.message.chat.id,f"К сожалению ответ неверный. Вы проиграли. Ваш заработок за эту игру {user['money']}$\nЕсли хотите попытаться еще раз:\nнажмите /game")
                    user['money'] = 0
                    user['question'] = 1
                    user['session']=0
                    user['Is_playing']=False
                   

    except Exception as e:
        print(repr(e))

    

@bot.message_handler(content_types=['text'])
def main(message):

    if message.text == "Рейтинг":
        user_id=str(message.chat.id)
        data_server =  requests.post('http://localhost:5000/rating',user_id)
        array=json.loads(data_server.text)
        if(len(array)>5):
            bot.send_message(message.chat.id, \
                f"*ТОП 5 ЛУЧШИХ ИГРОКОВ*\n\n*1.{array[0]['name'].upper()}*\t\t*{array[0]['money']}$*\n\n*2.{array[1]['name'].upper()}*\t\t*{array[1]['money']}$*\n\n*3.{array[2]['name'].upper()}*\t\t*{array[2]['money']}$*\n\n*4.{array[3]['name'].upper()}*\t\t*{array[3]['money']}$*\n\n*5.{array[4]['name'].upper()}*\t\t*{array[4]['money']}$*\n\n\n*Ваше место в топе:\t\t{array[5]['number']}*",parse_mode="Markdown")

        else:
            bot.send_message(message.chat.id, \
                f"*ТОП 5 ЛУЧШИХ ИГРОКОВ*\n\n*1.{array[0]['name'].upper()}*\t\t*{array[0]['money']}$*\n\n*2.{array[1]['name'].upper()}*\t\t*{array[1]['money']}$*\n\n*3.{array[2]['name'].upper()}*\t\t*{array[2]['money']}$*\n\n*4.{array[3]['name'].upper()}*\t\t*{array[3]['money']}$*\n\n*5.{array[4]['name'].upper()}*\t\t*{array[4]['money']}$*",parse_mode="Markdown")

    
    elif message.text == "/help":
        bot.send_message(message.chat.id, 'Отлично,что решил поиграть! Сейчас я расскажу тебе основные правила.\n*1.* Ты должен будешь отвечать на вопросы, которые с каждым разом будут становиться сложней.\n*2.* Вопрос предполагает 4 варинаты ответа и только 1 верный.\n*3.* За каждый верный вопрос ты будешь получать по 50$.\n*4.* Если ты ответил неправильно, то игра заканчивается.\n*5.* Лучшие умы, которые наберут больше всего денег за правильные вопросы, попадают в топ нашего бота.\n*ОСНОВНЫЕ КОМАНДЫ*\n*"/game"* - Команда, чтобы начать игру\n*"/stop"* - Команда,чтобы выйти из игры, если вы не хотите больше играть\n*Напишите в чате "Рейтинг"* - Вывод списка состоящего из 5 лучших игроков за все время',parse_mode="Markdown")
    
    
    
    else:
        bot.send_message(message.chat.id,"Не понимаю, что ты написал")

bot.polling(none_stop=True)  # запускаем бота
