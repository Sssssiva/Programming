#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
struct Passenger {
    int PassengerId;
    bool Survived;
    int Pclass;
    string Name;
    string Sex;
    int Age;
    int SibSp;
    int Parch;
    string Ticket;
    double Fare;
    string Cabin;
    string Embarked;
}Titanik;
int max_symbol = 0;
int max_znach(vector<Passenger>a) {
    for (int i = 0; i < a.size(); i++) {
        if (max_symbol < a[i].Name.size()) {
            max_symbol = a[i].Name.size();
        }
    }
    return max_symbol;
}

std::istream& operator >> (std::istream& file, vector<Passenger>& passengers) {


    bool znach = false;

    while (!file.eof()) {
        string temp;
        temp = "";
        if (!znach) {
            getline(file, temp, '\r');
            znach = true;
        }
        getline(file, temp, ',');
        int passengerId = stoi(temp);
        Titanik.PassengerId = passengerId;

        getline(file, temp, ',');
        bool survived = stoi(temp);
        Titanik.Survived = survived;



        getline(file, temp, ',');
        int pclass = stoi(temp);
        Titanik.Pclass = pclass;



        getline(file, temp, ',');
        string name = temp;
        if (name[name.length() - 1] != '"')      
        {
            getline(file, temp, ',');
            name += temp;
        }
        
        name.erase(0, 1);                   
        name.erase(name.size() - 1, 1);    
        Titanik.Name = name;



        getline(file, temp, ',');
        Titanik.Sex = temp;



        getline(file, temp, ',');
        if (temp == "") {
            temp = "0";
        }
        double age = stoi(temp);
        Titanik.Age = age;


        getline(file, temp, ',');
        int sibSp = stoi(temp);
        Titanik.SibSp = sibSp;


        getline(file, temp, ',');
        int parch = stoi(temp);
        Titanik.Parch = parch;

        getline(file, temp, ',');
        Titanik.Ticket = temp;


        getline(file, temp, ',');
        double fare = stoi(temp);
        Titanik.Fare = fare;


        getline(file, temp, ',');
        Titanik.Cabin = temp;


        getline(file, temp, '\r');
        Titanik.Embarked = temp;
        passengers.push_back(Titanik);

    }
    return file;
}

void sort(vector<Passenger*>& girls) {
    for (int i = 0; i < girls.size() - 1; i++) {
        for (int j = i; j < girls.size(); j++) {
            if (girls[i]->Age > girls[j]->Age) {
                swap(*girls[i], *girls[j]);
            }
        }
    }
}

vector<Passenger*> people(vector<Passenger>& passengers) {
    vector<Passenger*> girls;

    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i].Survived = true and passengers[i].Sex == "female" and passengers[i].Pclass == 1) {
            girls.push_back(&passengers[i]);
        }
    }
    sort(girls);
    return girls;
}



ostream& operator<< (ostream& ost, vector<Passenger>& passengers) {
    ost << "PassengerId" << " Survived" << "  Pclass\t"<< "\t\tName\t" << "\t\t\t\t\t\t\t\tSex\t" << "Age\t" << "SibSp\t" << "Parch\t" << "Ticket\t" << "Fare\t" << "Cabin\t" << "Embarked";
    ost << endl;

    for (int i = 0; i < passengers.size(); i++) {
        Passenger& p = passengers[i];
        ost<< p.PassengerId << "\t\t" << p.Survived << "\t" << p.Pclass<<"\t"<<left<< setw(max_symbol) << p.Name << "\t" << p.Sex << "\t" << p.Age << "\t" << p.SibSp << "\t" << p.Parch << "\t" << p.Ticket << "\t" << p.Fare << "\t" << p.Cabin << "\t" << p.Embarked << endl;
    }

    return ost;
}

int main() {
    
    std::ifstream file;
    file.open("train.csv");
    vector<Passenger> passengers;
    file >> passengers;
    max_znach(passengers);
    people(passengers);
    ofstream csv;
    csv.open("file.csv");
    csv << passengers;
}
