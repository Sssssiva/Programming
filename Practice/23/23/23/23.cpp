#include <iostream>
#include "sag.h"
#include "header.h"
#include "second.h"
#include <iomanip>
int main()
{
    double x;
    int k=5,n=10;
    const double P = 3.141592;
    std::cout << "n\t" << "n!" << std::endl;
    for (int x = 0; x <= 10; x++) {
        std::cout << x<<"\t";
        std::cout << fact(x) << std::endl;
    }
    std::cout << "x\t" << "sin(x)" << std::endl;
    for (double x = 0; x <= (P / 4); x += (P / 180)) {
        std::cout << x << "\t";
        std::cout << std::setprecision(4) << asc(x, k) << std::endl;
    }
    std::cout << "k\t" << "C(k, 10)"<<std::endl;
    for (k = 1; k <= 10; k++) {
        std::cout << k << "\t";
        std::cout << ck(k, n)<<std::endl;
    }
}

