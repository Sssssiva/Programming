#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    cin >> a >> b;
    c = a;
    a = b;
    b = c;
    cout << "а=" << a <<endl<< "b=" << b << endl;
    cout << "next programm" << endl;
    a = 0;
    b = 0;
    cin >> a>> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a=" << a << endl << "b=" << b << endl;
}

