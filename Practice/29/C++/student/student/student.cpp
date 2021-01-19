#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<ctime>
int max_symbols = 0;
struct student {
	std::string name;
	int group;
	struct object {
		int mathematics;
		int physics;
		int history;
		int programming;
	}exams;

};
int max(std::vector<student>losers){
	int max_symbols = 0;
	for (int i = 0; i < losers.size(); i++) {
		if (max_symbols < losers[i].name.size()) {
			max_symbols = losers[i].name.size();
		}

	}
	return max_symbols;
}
bool operator<(student a, student b) {
	return a.name < b.name;
}
std::ostream& operator<<(std::ostream& out, student temp) {
	out << "|" << std::left << std::setw(10) << temp.name << "|"
		<<std::setw(7)<< temp.group << "|"
		<< std::setw(6) << temp.exams.mathematics << "|"
		<< std::setw(6) << temp.exams.physics << "|"
		<< std::setw(6) << temp.exams.history << "|"
		<< std::setw(6) << temp.exams.programming << "|";	
	return out;
}


std::vector<student>Bozosort(std::vector<student>Data) {
	bool ch = false;

	while (!ch) {
		int i1 = rand() % Data.size();
		int i2 = rand() % Data.size();
		student sw = Data[i1];
		Data[i1] = Data[i2];
		Data[i2] = sw;
		ch = true;
		for (int i = 1; i < Data.size(); i++) {
			if (Data[i] < Data[i-1]) {
				ch = false;
				break;
			}
			
		}
	}
	return Data;
}

int main() {
	std::vector<student> list,losers;
	student A{ "Ivanov A", 202, {5, 5, 5, 5} };
	list.push_back(A);
	A = { "Gabrian G", 201, {4, 5, 2, 5} };
	list.push_back(A);
	A = { "Jafro K", 202, {5, 3, 4, 3} };
	list.push_back(A);
	A = { "Ebro I", 202, {4, 5, 5, 5} };
	list.push_back(A);
	A = { "Demiht E", 201, {2, 4, 2, 4} };
	list.push_back(A);
	A = { "Zaycev W", 201, {3, 3, 3, 3} };
	list.push_back(A);
	A = { "Burganov F", 201, {2, 5, 5, 5} };
	list.push_back(A);
	A = { "Sayd T", 202, {3, 3, 3, 3} };
	list.push_back(A);
	A = { "Aleym C", 202, {3, 3, 4, 3} };
	list.push_back(A);
	A = { "Andreev S", 202, {5, 5, 5, 5} };
	list.push_back(A);
	for (int i = 0; i< list.size(); i++) {
		if ((list[i].exams.history == 2) or (list[i].exams.mathematics == 2) or (list[i].exams.physics == 2) or (list[i].exams.programming == 2)) {
			losers.push_back(list[i]);
		}

	}
	if (losers.size()) {
		max_symbols = max(losers);
		losers = Bozosort(losers);
		std::cout << "+----------+-------+------+------+------+------+" << std::endl;
		std::cout << "|  Name    | Group | Math | Phys | Hist | Prog |";
		std::cout << std::endl << "+----------+-------+------+------+------+------+" << std::endl;
		for (student data : losers) {
			std::cout << data;
			std::cout << std::endl << "+----------+-------+------+------+------+------+" << std::endl;
		}
		std::cout << std::endl << "Exlucion" << std::endl;
		srand(time(0));
		int i1 = rand() % losers.size();
		std::cout<<std::endl<< "+----------+-------+------+------+------+------+" << std::endl;
		std::cout << "|  Name    | Group | Math | Phys | Hist | Prog |" << std::endl;
		std::cout << "+----------+-------+------+------+------+------+" << std::endl;
		std::cout << losers[i1] << std::endl;
		std::cout << "+----------+-------+------+------+------+------+" << std::endl;

	}
	else {
		std::cout << "Not found";
	}





}