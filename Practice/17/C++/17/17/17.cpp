#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int a[37] = { 0 }, b[37] = { 0 }, c = 0,red=0,black=0, n;
	while (1) {
		cin >> n;
		if (n < 0) {
			exit(1);
		}
		a[n]++;
		b[n]++;
		for (int i = 0; i < 37; i++) {
			if (a[i] > c) {
				c = a[i];
			}
		}
		for (int i = 0; i < 37; i++) {
			if (a[i] == c) {
				cout << i << " ";
			}
		}
		cout << endl;
		for (int i = 0; i < 37; i++) {

			if (b[i] == 0) {
				cout << i << " ";
			}
		}
		if (n == 1 or n == 3 or n == 5 or n == 7 or n == 9 or n == 12 or n == 14 or n == 16 or n == 18 or n == 19 or n == 21 or n == 23 or n == 25 or n == 27 or n == 30 or n == 32 or n == 34 or n == 36) {
			red += 1;
		}
		else {
			black += 1;
		}
		cout<<"\n" << red << " " << black << endl << endl;
	}
}