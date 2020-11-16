#include <iostream>
#include "sag.h"
#include "header.h"
#include "second.h"
#include <iomanip>
int main()
{
    double x;
    int k,n;
    std::cin >> x;
    std::cout << fact(x)<<std::endl;
    std::cin >> x >> k;
    std::cout <<std::setprecision(4)<< asc(x, k)<<std::endl;
    std::cin >> k>>n;
    std::cout << ck(k, n);

}

