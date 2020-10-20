#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int n,res=1;
    cout << "N"<<endl;
    cin >> n;
    if (n > 0) {
        for (int i = 2; i <= n; i++) {
            res = res * i;
        }
        cout << res;
    }
    if (n < 0) {

        cout << "отрицательное число";
        
    }
    if (n == 0) {

        cout << "0";
    }
}