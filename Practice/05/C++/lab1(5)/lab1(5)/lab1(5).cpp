#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double x_t, x0, v0, t;
    const double a = 9.8;
    cout << "Введите значение x(0): ";
    cin >> x0;

    cout <<endl<< "Введите значение v(0): ";
    cin >> v0;
    cout <<endl<< "Введите значение t: ";
    cin >> t;
    x_t = x0 + v0 * t - (a * t * t / 2);
    cout <<endl<<"Ответ первый: " << x_t << endl;
    x_t = x0 + v0 * t - (1 / 2 * a * t * t);
    cout << "Ответ второй: " << x_t;

}

