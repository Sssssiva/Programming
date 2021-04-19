#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const auto PI = 3.141592653589793;
enum coord_system {
    Cartesian,
    Polar
};

class Point {
    double a1, a2;
    coord_system thirt;
public:
    Point(double a1 = 0, double a2 = 0, coord_system thirt = Cartesian) {
        if (thirt == Cartesian) {
            this->a1 = a1;
            this->a2 = a2;
        }
        else {
            this->a1 = a1 * cos(a2);
           this->a2 = a1 * sin(a2);
        }
    }
    double get_x() {
        return a1;
    }
    double get_y() {
        return a2;
    }
    double get_r() {
        return sqrt((a1*a1)+(a2*a2));
    }
    double get_phi() {
        return atan2(a2,a1);
    }
    double set_x(double a) {
        return a1 = a;
    }
    double set_y(double a) {
        return a2 = a;
    }
    double set_r(double r) {
        double phi = get_phi();
        a1 = cos(phi) * r;
        a2 = sin(phi) * r;
        return a1, a2;
    }
    double set_phi(double phi) {
        double r = get_r();
        a1 = cos(phi) * r;
        a2 = sin(phi) * r;
        return a1, a2;
    }

   friend ostream& operator<<(ostream& out, Point& point);
   friend istream& operator>>(istream& in, Point& point);


   bool operator==(Point& point) {
       if (abs(get_x() - point.get_x() < pow(10, -10)) and abs(get_y() - point.get_y() < pow(10, -10)))
           return true;
       else
           return false;
   }
   bool operator!=(Point& point) {
       if (abs(get_x() - point.get_x() > pow(10, -10)) or abs(get_y() - point.get_y() > pow(10, -10)))
           return true;
       else
           return false;
   }

};


    ostream& operator<<(ostream& out, Point& point) {

        out<< "(" << point.get_x() << "," << point.get_y() << ")" << endl;
        return out;
    }
    istream& operator>>(istream& in, Point& point) {
        double x,y;
        in.ignore(1);
        in >> x;
        point.set_x(x);
        in.ignore(1);
        in >> y;
        point.set_y(y);
        in.ignore(1);
        return in;
    }


int main() {

    std::vector<Point> original;
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
    else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
