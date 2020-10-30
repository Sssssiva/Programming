#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n,k=1;
	string b;
	string c = "";
	cout << "Введите кол-во билетов" << endl;
	cin >> n;
	cout << "Введите номера билетов через пробел" << endl;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if ((b[0] == 'a') and (b[4] == '5') and (b[5] == '5') and (b[6] == '6') and (b[7] == '6') and (b[8] == '1')) {
			c += b + " ";
			k += 1;
		}
	
	}
	if (k == 1) {
		cout << "-1";
	}
	else {
		cout << c;
	}
 }