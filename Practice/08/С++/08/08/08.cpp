#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double x1, x2,res;
    char sym;
    cout << "Введите через пробел вещественное число, затем символ - знак операции и вещественное число" << endl;
    cin >> x1 >> sym >> x2;
    if (sym != '+' && sym != '-' && sym != '*' && sym != '/') {
        cout<<"Ошибка ввода действия. Ожидалось + - * / , а не "<<sym; 
    }
    
    
    if (sym == '+') {
        res = x1 + x2;
        cout << res;
    }

    if (sym == '-') {
        res = x1 - x2;
        cout << res;
    }

    if (sym == '*') {
        res = x1 * x2;
        cout << res;
    }

    if (sym == '/') {
        res = x1 / x2;
        cout << res;
    }



}


