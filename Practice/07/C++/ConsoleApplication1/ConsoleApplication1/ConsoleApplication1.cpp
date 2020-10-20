#include <iostream>
#include "ConsoleApplication1.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int input;
    double a, b, c, p,S,x1,y1,x2,y2,x3,y3;
    cout << "1 - ввод параметров треугольника через длины сторон." << endl;
    cout << "2 - ввод параметров через координаты вершин" << endl;
    cout << "Любое другое число - ошибочный ввод" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "Введите значения сторон треугольника:"<<endl;
        cin >> a >> b >> c;
        if ((a == 0 || b == 0 || c == 0) || (a + b < c || a + c < b || b + c < a)) {
            cout << "Введены неверные данные стороны а или стороны b или стороны c";
        }
        else {
            p = 0.5 * (a + b + c);
            S = sqrt(p * (p - a) * (p - b) * (p - c));
            cout << "S=" << S;
        }
    }
    if (input != 2 && input != 1) {
        cout << "Неверный ввод";
    }
    if (input == 2) {
        cout << "Ввод параметров через координаты вершин: "<<endl;
        cout << "Ввод первой точки: ";
        cin >> x1 >> y1;
        cout << "Ввод второй точки: ";
        cin >> x2 >> y2;
        cout << "Ввод третьей точки: ";
        cin >> x3 >> y3;
        if ((x1 == x2 && y1 == y2)||(x2==x3&&y2==y3)||(x1==x3&&y1==y3)) {
            cout << "Неверные данные первой, второй или  точки";
        }
        else {
           S= 0.5 * abs(((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)));
           cout << "S=" << S;
        }




       

    }
}