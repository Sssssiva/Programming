#include <iostream>
#include "sag.h"
#include "header.h"
int main()
{
    long int x;
    int k,n;
    std::cin >> x;
    std::cout << fact(x)<<std::endl;
    std::cin >> k>>n;
    std::cout << ck(k, n);
}

