#include <iostream>
#include <nlohmann/json.h>
#include<iomanip>
#include<fstream>
#include <string>
#include <cpp_httplib/httplib.h>
using json = nlohmann::json;
using namespace httplib;
using namespace std;
json jtime;
json jcache;
string ht;
json memory;
bool baal = false;

void cli() {
	ifstream fil("weather.html");
	getline(fil, ht, '\0');
	Client cli("http://api.openweathermap.org");
	auto data = cli.Get("/data/2.5/onecall?lat=44.948237&lon=34.100318&exclude=current,minutely,daily,alerts&units=metric&lang=ru&APPID=842fc3a1dc489d72adfd0262976857ba");

	if (data) {
		if (data->status != 200) {
			std::cout << "Status code: " << data->status << std::endl;
		}
	}
	else {
		auto err = data.error();
		std::cout << "Eror code: " << err << std::endl;

	}
	httplib::Client time("http://worldtimeapi.org");
	auto data1 = time.Get("/api/timezone/Europe/Simferopol");

	if (data1) {
		if (data1->status != 200) {
			std::cout << "Status code: " << data1->status << std::endl;
		}
	}
	else {
		auto err = data1.error();
		std::cout << "Eror code: " << err << std::endl;

	}

	jtime = json::parse(data1->body);
	if (jcache.empty()) {
		jcache = json::parse(data->body);

	}
	for (int i = 0; i < jcache["hourly"].size(); i++) {
		if (jcache["hourly"][i]["dt"] > jtime["unixtime"]) {
			baal = true;
			memory = jcache["hourly"][i];
			break;
		}
	}
	if (!baal) {
		jcache = json::parse(data->body);
	}
}


void gen_response(const Request& req, Response& response) {
	cli();
	string html = ht;
	std::string str2 = "{hourly[i].weather[0].description}";
	std::string str3 = "{hourly[i].weather[0].icon}";
	std::string str4 = "{hourly[i].temp}";
	html.replace(html.find(str2), str2.length(), memory["weather"][0]["description"]);
	html.replace(html.find(str3), str3.length(), memory["weather"][0]["icon"]);
	html.replace(html.find(str4), str4.length(), to_string(int(memory["temp"].get<double>())));
	html.replace(html.find(str4), str4.length(), to_string(int(memory["temp"].get<double>())));

		response.set_content(html, "text/html");

	
}

void raw(const Request& req, Response& response) {
	ifstream fil("weather.html");
	getline(fil, ht, '\0');
	Client cli("http://api.openweathermap.org");
	auto data = cli.Get("/data/2.5/onecall?lat=44.948237&lon=34.100318&exclude=current,minutely,daily,alerts&units=metric&lang=ru&APPID=842fc3a1dc489d72adfd0262976857ba");

	if (data) {
		if (data->status != 200) {
			std::cout << "Status code: " << data->status << std::endl;
		}
	}
	else {
		auto err = data.error();
		std::cout << "Eror code: " << err << std::endl;

	}
	httplib::Client time("http://worldtimeapi.org");
	auto data1 = time.Get("/api/timezone/Europe/Simferopol");

	if (data1) {
		if (data1->status != 200) {
			std::cout << "Status code: " << data1->status << std::endl;
		}
	}
	else {
		auto err = data1.error();
		std::cout << "Eror code: " << err << std::endl;

	}

	jtime = json::parse(data1->body);
	if (jcache.empty()) {
		jcache = json::parse(data->body);

	}
	for (int i = 0; i < jcache["hourly"].size(); i++) {
		if (jcache["hourly"][i]["dt"] > jtime["unixtime"]) {
			baal = true;
			memory = jcache["hourly"][i];
			break;
		}
	}
	if (!baal) {
		jcache = json::parse(data->body);
	}
	json push;

	push["d"] = memory["weather"][0]["description"];
	push["t"] = memory["temp"];

	response.set_content(push.dump(), "text/json");
}

int main(){
	
	Server srv;
	srv.Get("/", gen_response);
	srv.Get("/raw", raw);
	
	std::cout << "Start server..." << std::endl;
	srv.listen("localhost", 3000);
	
}