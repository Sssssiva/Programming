#include <iostream>
#include <stdlib.h>
#include<ctime>
using namespace std;
int main()
{ 
	setlocale(LC_ALL, "Rus");
	int a,b,c;
tryagain:
	srand(time(NULL));
	a = rand()%101;
	cout << "Называй число" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		if (b > a) {
			cout << "Ваше число больше загаданного." << endl;
		}
		if (b < a) {
			cout << "Ваше число меньше загаданного." << endl;
		}
		if (b == a) {
			cout << "Вы выиграли!\n Хотите сыграть еще раз? Если да,то введите 1" << endl;
			cin >> c;
			if (c == 1) {
				goto tryagain;
			}
			else {
				exit(1);
			}
		}
	}
	cout << "Загаданное число:" << a<<endl  ;
	cout << "Вы проиграли(\n Хотите сыграть еще раз?\nЕсли да,то введите 1"<<endl;
	cin >> c;
	if (c == 1) {
		goto tryagain;
	}
	else {
		exit(1);
	}
	
}
                  