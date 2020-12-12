#include <iostream>
#include<cmath>
using namespace std;
int mnojitel(int n, int number) { //проверка делимости и неделимости
    if( (n % number == 0) and (n > 1)) {
    return 1;
}
    else {//если не делится на текущий множитель number или n=1
        return 0;
    }
}
void print_factorization(int n) { 
    int proverka;
    int number = 2;
    int count;
    bool delaem = true;
    while (delaem)
    {
        count = 0;
        proverka = mnojitel(n, number);//отправляем на проверку в функцию
        while (proverka)//если пришло 1, то есть число делится на текущий множитель number 
        {
            count++;
            n = n / number;// делим на множитель, чтобы найти кол-во одинаковых сомножителей
            proverka = mnojitel(n, number);// отправляем на проверку 
        }
        if (count > 0)//вывод в консоль
        {
                cout << number;
            if (count > 1)
                cout << '^' << count;//кол-во сомножителей 
            if (n > 1)
                cout << '*';
        }
        number++;//увеличиваем множитель и проверяем дальше 
        if (n <= 1)//если все сделали или число не имее множителей, кроме себя
            delaem = false;//тогда выход
    }
}


int main(){
    int n;
    cin >> n;
    if (n < 2) {//проверка на ввод единицы или меньшего
        cout << "1";
    }
    print_factorization(n);//передаем число в функцию
}
