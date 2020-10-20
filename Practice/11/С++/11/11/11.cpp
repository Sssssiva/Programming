#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double ch, st, res=1;
	int i = 0;
	cout << "Введите число, а потом степнь в которую его нужно возвести" << endl;
	cin >> ch >> st;
	if (st > 0) {
		for (i; i < st; i++) {
			res = res * ch;
		}
		cout << res;
	}
	if (st < 0) {

		for (i; i < abs(st); i++) {
			res = res * abs(ch);
		}
		cout << 1/res;
	}
	if (st == 0) {
		cout << "1";
	}
}
