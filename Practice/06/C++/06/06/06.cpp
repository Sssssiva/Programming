#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b, c, x,x1,x2,d;
   cin >> a ;
   cin >> b;
   cin >> c;
	if (a != 0 && b != 0 && c!= 0) {
	 
	   d = b * b - 4 * a * c;
	   if (d > 0) {
		   x1 = (-b - sqrt(d)) / (2 * a);
		   x2 = (-b + sqrt(d)) / (2 * a);
		   cout << "x1=" << x1 << endl << "x2 =" << x2;
	   }
	   if(d<0) {
		   cout << "корней нет";
	   }
	   if (d == 0) {

		   x = -b / (2 * a);
		   cout << "x=" << x;
	}
   }
	if (a == 0 && b!=0 && c!=0) {
	   x=-c / b;
		   cout << "x=" << x;
}
	if (a == 0 && b == 0 && c == 0) {
		cout << "Множество корней";
	}

	if (a != 0 && b != 0 && c == 0) {

		cout << "x1=0" << endl << "x2=" << b/a ;
	}
}
