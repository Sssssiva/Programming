#include <iostream>
#include <string>
#include <iomanip>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.h>
using namespace std;
using namespace httplib;
using json = nlohmann::json;


string webhooks_list = "{webhooks_list}";//ищем в html
string Webhook_URL = "{Webhook URL}";//ищем в шаблоне
string shablon = u8R"(
<div class="form-row align-items-center">
    <div class="col">
        <input type="text" value="{Webhook URL}" class="form-control mb-2" disabled>
    </div>
    <div class="col">
        <button type="submit" name="del" value="{Webhook URL}" class="btn btn-danger mb-2">Удалить</button>
    </div>
</div>)";

ofstream file_text("log.txt");//файл лог в папке с cpp

json config_json;//json переменная

json open_file()//проверяет открытие файлов
{
    ifstream cache("config.json");//открываем файл в переменной cache 
    json config_json;
    file_text << u8"Пробуем открыть конфигурационный файл" << endl;//вывод в наш текстовый файл
    if (cache.is_open())//проверяем открылся config.json или нет
    {
        cache >> config_json;//передаем значение в джсон переменную
        file_text << u8"Конфигурационный файл открыт" << endl;//вывод сообщения 
    }
    else//иначе
    {
        file_text << u8"Не удалость открыть конфигурационный файл" << endl;//вывод в текстовый файл
        config_json["webhooks"] = json::array();//создаем пустой массив вебхуков
    
    }

    return config_json;
}

void save_config(json config_json)//обновляем файл
{
    ofstream cache("config.json");//создаем файл

    if (cache.is_open())//если он открылся,то
    {
        cache << config_json.dump(4);//записываем переменную json типа в наш файл
        cache.close();//закрываем его
        file_text << u8"Обновлен конфигурационный файл" << endl;
    }
    else
    {
        file_text << u8"Конфигурационный файл не удалось открыть" << endl;
    }
}

string good_html()//редактируем html код и вывод его
{
    string webhooks_template, AllWebHooks;
    ifstream webhooks_cache("web_html.html");//открываем файл 

    if (webhooks_cache.is_open())//если он открыт
    {
        getline(webhooks_cache, webhooks_template, '\0');//в переменную 2 записываем переменную 1
        webhooks_cache.close();
    }
    else
    {
        return "";
    }

    if (config_json.empty())//если он пустой
    {
        config_json = open_file();//в конфиг джсон записываем вывод функции
    }
    if (config_json["webhooks"].size())//если он не пустой
    {
        for (int i = 0; i < config_json["webhooks"].size(); i++)//редактируем наш код для замены в основном файле html
        {
            string OneWebhook = shablon;
            OneWebhook.replace(OneWebhook.find(Webhook_URL), Webhook_URL.length(), config_json["webhooks"][i]);
            OneWebhook.replace(OneWebhook.find(Webhook_URL), Webhook_URL.length(), config_json["webhooks"][i]);
            AllWebHooks = AllWebHooks + OneWebhook;
        }
        webhooks_template.replace(webhooks_template.find(webhooks_list), webhooks_list.length(), AllWebHooks);
    }
    else//если пустой
    {
        webhooks_template.replace(webhooks_template.find(webhooks_list), webhooks_list.length(), "");//заменяем на пустоту
    }
    return webhooks_template;
}

void del_set_webhooks(const Request& req)//добавляем и удаляем вебхуки
{
    if (config_json.empty())//если он пустой, то обращаемся в функцию и записываем ее вывод в переменную config_json
    {
        config_json = open_file();
    }

    if (req.has_param("del"))//если поступил параметр удалить,то
    {
        string webhook_to_remove = req.get_param_value("del");//название вебхука, который нужно удалить
        for (int i = 0; i < config_json["webhooks"].size(); i++)//ищем файл, который нужно удалить
        {
            
            if (config_json["webhooks"][i] == webhook_to_remove)//если оно нашлось 
            {
                string f = config_json["webhooks"][i];
                config_json["webhooks"].erase(config_json["webhooks"].begin() + i);//удаляем этот вебхук
                file_text << u8"Удалён webhook " << f << endl;//заносим файл
                break;//выход
            }
        }
    }
    else if (req.has_param("set"))//если параметр "добавить"
    {

        if (req.get_param_value("set") == "")//если пользователь добавил пустой вебхук
        {
            file_text << u8"Получен пустой webhook" << endl;
        }
        else//если не пустое имя,то
        {
            file_text << u8"Получен запрос на добавление webhook " << req.get_param_value("set") << endl;
            bool check = false;
            if (config_json["webhooks"].size())//если есть хоть один вебхук 
            {
                for (int i = 0; i < config_json["webhooks"].size(); i++)//проверяем на наличие совпадений
                {
                    if (config_json["webhooks"][i] == req.get_param_value("set"))
                    {
                     
                        check = true;
                        break;
                    }
                }
            }
            if (!check)//если совпадений нет, то мы его добавляем 
            {
                file_text << u8"Добавлен webhook " << req.get_param_value("set") << endl;
                config_json["webhooks"].push_back(req.get_param_value("set"));
            }
        }
    }
    save_config(config_json);//передаем полученное значеное в функцию
    
}

void webhooks_post_resp(const Request& req, Response& res)//отправляем пост запрос
{
    del_set_webhooks(req);
    string output = good_html();
    res.set_content(output, "text/html; charset=UTF-8");
}

void webhooks_page(const Request& req, Response& res)//гет запрос
{
    string output = good_html();
    res.set_content(output, "text/html");
}

int main()
{
    Server WH;
    WH.Post("/webhooks", webhooks_post_resp);//вызываем пост 
    WH.Get("/webhooks", webhooks_page);//вызываем гет
    cout << "Server started..." << endl;
    file_text << u8"Сервер запущен без ошибок" << endl;
    WH.listen("localhost", 1234);
}