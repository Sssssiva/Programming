#ifndef dag
#define dag
#include"SAG.h"
#include<cmath>
double asc(double x, int k) {
	double sum;
	sum = 0;
	
	for (int i = 0; i < k; i++) {

		sum += (pow((-1), i) * ((pow(x, 2 * i + 1)) / (fact(2 * i + 1))));
	}

	return sum;
}

#endif // !1
