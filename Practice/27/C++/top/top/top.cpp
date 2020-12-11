#include <iostream>
#include<vector>
#include <ctime>
using namespace std;
vector<int>Sort(vector<int>Data) {
	bool ch = false;
	while (!ch) {
		int i1 = rand() % Data.size();
		int i2 = rand() % Data.size();
		int sw = Data[i1];
		Data[i1] = Data[i2];
		Data[i2] = sw;
		ch = true;
		 
			for (int i = 1; i < Data.size(); i++) {
				if (Data[i - 1] < Data[i]) {
					ch = false;
					break;
				}
			}
		}
	
		return Data;
}
void input(int sign, int kolvo, vector<int>Data){
	for (sign; sign < kolvo; sign++) {
		cout << Data[sign]<<"\t";
	}
	cout << endl;
}

int main()
{
	int kolvo = 0;
	int sign = 0;
	int n;
	cin >> n;
	vector<int>output;
	vector<int>Data(n);
	for (int i = 0; i < n; i++) {
		cin >> Data[i];
		cout << endl;
		kolvo++;
		if(kolvo < 6) {
		output= Sort(Data);
		input(sign, kolvo, output);
		}
		if(kolvo>5) {
			sign = kolvo - 5;
			output = Sort(Data);
			input(sign, kolvo, output);
		}
	


	}	
	 
}