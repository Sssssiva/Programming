#include <iostream>
using namespace std;
double BMI();
double BMI(double weight, double height)
{   
    double x;
	x=(weight / pow(height / 100, 2));
    return x;
}
void printBMI(double BMI)
{
    if (BMI < 18.5) {
        cout << ("Underweight");
    }
    if (BMI >= 18.5 and BMI < 25.0) {
        cout << ("Normal");
    }
    if (BMI >= 25.0 and BMI < 30.0) {
            cout << ("Overweight");
        }
    if (BMI >= 30.0) {
        cout << ("Obesity");
    }
 
}
int main(){
    double weight, height;
    cin >> weight >> height;
         printBMI(BMI(weight,height));
}
