﻿// 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    long long int s, l1, r1, l2, r2;
    cout << "Введите s, l1, r1, l2, r2, x1, x2 " << endl;
    cin >> s >> l1 >> r1 >> l2 >> r2;
    if ((l1 >= r1) || (l2 >= r2)) {
        cout << "Неправильный ввод";
        exit(1);
    }
    if ((l1 + r2)-s== 0) {
        cout << "x1= " << " " << l1 << "x2=" << r2;
        exit(1);
    }
    if ((l1 + r2) - s > 0) {
        cout << "x1=" << l1 << " " << "x2=" << r2 - ((r2 + l1)-s);
        exit(1);
    }
    if ((l1 + r2) - s < 0) {
        cout << "x1=" << l1 - ((l1 + r2) - s)<<" " << "x2=" << r2;
        exit(1);
    }
    if ((r1 + r2 != s) && (r1 + l2 != s) && (l1 + r2 != s) && (l1 + l2 != s)) {
        cout << "-1";
    }
}