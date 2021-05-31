#include <cpp_httplib/httplib.h>
#include <iostream>
#include <nlohmann\json.hpp>
#include <ctime>
#include <algorithm>
#include<iomanip>
using namespace httplib;
using namespace nlohmann;
using namespace std;

json ar;
int quantity;
std::map<std::string, std::vector<int> > answered_table;

struct People {
    string name;
    int money;
    string id;
    int question;
};



json open_file(string a)//проверяет открытие файлов
{
    ifstream cache(a);//открываем файл в переменной cache 
    json file_json;
    if (cache.is_open())//проверяем открылся файл .json или нет
    {
        cache >> file_json;//передаем значение в джсон переменную 
    }
    else//иначе
    {

        cout << u8"Не удалость открыть конфигурационный файл" << endl;

    }

    return  file_json;
}

void function_name(const httplib::Request& req, httplib::Response& res) {//функция для выдачи вопроса пользователю
   quantity = stoi(req.get_param_value("question"));
   string session = req.get_param_value("session");
   if (quantity == 11 or quantity==21) {
       answered_table[session].clear();
   }
   try {
        
        string file;
        if (quantity <= 10) {
            cout << "2";
            file = "easy.json";
            ar = open_file(file);
        }

        if (quantity > 10 and quantity <= 20) {
            
           
            file = "middle.json";
            ar = open_file(file);
        }
        if (quantity > 20) {
            
            file = "hard.json";
            ar = open_file(file);
        }
    }
    catch (std::exception& e) { std::cout << e.what(); }

    
    
    
	srand(time(0));
	int size = ar.size();
    int index;
    if (ar.size() == answered_table[session].size()) {//если он ответил на все вопросы
        answered_table[session].clear();
    }
    while (true) {//выполняется пока не найдется нужный вопрос
        vector<int>& V = answered_table[session];//массив отвеченных вопросов
        index = rand() % size;//берем рандомный  индекс вопроса
        if (binary_search(begin(V), end(V), index)) {//если этот вопрос уже отправлен

            continue;//ищем следующий
        }
        V.push_back(index);//помечаем его как отмеченный и добавляем в массив
        sort(begin(V),end(V));//сортируем массив
        break;
    }
	res.set_content(ar[index].dump(), "text/plain;charset=UTF-8");//отправляем вопрос
}
void delete_session(const httplib::Request& req, httplib::Response& res) {//удаляем сессию проигравшего пользователя
   
    answered_table[req.body].clear();
    
}
void rating(const httplib::Request& req, httplib::Response& res) {
    string file = "top.json";
    json array = (open_file(file));
    json temp;
    string id = req.body;
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j]["money"].get<int>() < array[j + 1]["money"].get<int>()) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
        }
    }
    int number=0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i]["id"] == id) {
            number = i + 1;
        }
    }
   
    
    json top;
    for (int i = 0; i < 5; ++i) {
        top.push_back(array[i]);
    }
    if (number > 5) {
        top.push_back({ {"name", array[number-1]["name"]},
                {"money", array[number-1]["money"]},
                {"id", array[number-1]["id"]},
            {"number", number} });
    }
    cout << setw(2) << top;
    
    res.set_content(top.dump(), "text/plain;charset=UTF-8");
}
void top(const httplib::Request& req, httplib::Response& res) {
    if (req.has_param("name")&& req.has_param("id") && req.has_param("money")) {
       
        string file = "top.json";
        json array = (open_file(file));
        People player;
        player.name = req.get_param_value("name");
        player.money = std::stoi(req.get_param_value("money"));
        player.id= req.get_param_value("id");



        bool not_found = true;
        for (json& person : array)
        {
            
            if (person["id"] == player.id)// нашли человека
            {
                
                int money = person["money"].get<int>();
                if (money < player.money)
                {
                    
                    person["money"] = player.money;
                }
                not_found = false;
                break;
            }
        }
        if (not_found)// не нашли
        {
            
            json new_person = {
                {"name", player.name},
                {"money", player.money},
                {"id", player.id},
            };

            array.push_back(new_person);
        }

        
        ofstream json_file("top.json");
        if (json_file.is_open()) json_file<<setw(2) << array;



    }
    else {
        cout << "Bad request";
    }

}



int main()
{
    
	
	Server srv;
	srv.Post("/get_q", function_name);
    srv.Post("/delete", delete_session);
    srv.Post("/top", top);
    srv.Post("/rating", rating);
	srv.listen("localhost", 5000);
    
    /*srv.set_exception_handler([](const httplib::Request&, httplib::Response& res, std::exception& e) {
    std::cout<< "Exception: "<< e.what() << std::endl;
        nlohmann::json j{ {"status", "server-error"} };
        res.set_content(j.dump(2), "text/json; charset=utf-8");
        });*/
}
