#include <iostream>
using namespace std;
int main()
{
    int a;
    setlocale(LC_ALL, "rus");
    cin >> a;
    if (a > 1) {
        if (a == 5 or a == 2 or a == 3) {
            cout << a << "-простое";
            exit(1);
        }
        if (a % 2 != 0 and a % 3 != 0 and a % 5 != 0) {
            cout << a << "-простое";
        }
        if (a % 2 == 0 or a % 3 == 0 or a % 5 == 0) {
            cout << a << "-составное";
        }
    }
    else {
        cout << "Неправильный ввод";
    }
}