#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
    cout <<"Ввeдите два значения времени в виде часов и минут"<<endl;
	double h1, m1, h2, m2,One,Two,Res;
	char a, b;
	cin >> h1 >> a >> m1;
	if ((h1 >=24 || h1<0) || (m1<0 || m1 >= 60)) {

		cout << "Неверный ввод данных h1";
		exit(1);
	}
	cin >> h2 >> b >> m2;
	if ((h2 >= 24 || h2 < 0) || (m2 < 0 || m2 >= 60)) {

		cout << "Неверный ввод данных h2";
		exit(1);
	}
	One = h1 * 60 + m1;
	Two = h2 * 60 + m2;
	Res = abs(One - Two);
	if (Res>15){
		cout << "Встреча не состоится";
	}
	else {
		cout << "Встреча состоится";
	}
}