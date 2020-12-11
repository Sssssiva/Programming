#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
/*int random(int gata) {
	srand(time(0));
	return rand() % gata;
}*/

vector<int>Bozosort(vector<int>Data,bool sign=true){
	bool ch = false;
	
	while (!ch) {
		int i1 = rand() % Data.size();
		int i2 = rand() % Data.size();
		int sw = Data[i1];
		Data[i1] = Data[i2];
		Data[i2] = sw;
		ch = true;
		if (!sign) {
			for (int i = 1; i < Data.size(); i++) {
				if (Data[i - 1] < Data[i]) {
					ch = false;
					break;
				}
			}
		}

		else {
			for (int i = 1; i < Data.size(); i++) {
				if (Data[i - 1] > Data[i]) {
					ch = false;
					break;
				}
			}
		}
	}
		return Data;
	
}
vector <int>Bozosort(vector<vector<int> > Data, bool sign = true) {
	vector<int>Two;
	for (int i = 0; i < Data.size(); i++) {
		for (int j = 0; j < Data.size(); j++) {
			Two.push_back(Data[i][j]);
		}
	}
	if (sign) {
		return Bozosort(Two);
	}
	if(!sign) {
		return Bozosort(Two, false);
	}
}
vector <int>Bozosort(int one, int two, int three, bool signe = true) {
	bool gg = false;
	vector <int>func(3);
	func[0] = one;
	func[1] = two;
	func[2] = three;
	if (!signe) {
		return Bozosort(func, false);
	}
	else {
		return Bozosort(func);
	}
}
int main(){
	srand(time(0));
//кол-во чисел
	int n;
//Ввод кол-ва чисел
	cin >> n;
//вектор для первой функции
	vector<int>Data(n);
//заполнение первого вектора
	for (int i = 0; i < n; i++) {
		cin >> Data[i];
	}
//вывод первой функции
	vector<int>output(Data.size());
	output=Bozosort(Data);
//при тру
	for (int i = 0; i < Data.size(); i++) {
		cout << output[i];
	}
	cout << endl;
	output=Bozosort(Data, false);
// при фолс
	for (int i = 0; i < Data.size(); i++) {
		cout << output[i];
	}
	cout << endl;
	int info = 0;
	vector<vector<int>>Dataa;
	for (int i = 0; i < sqrt(n); i++) {
		std::vector<int> massive;
		for (int i = 0; i < sqrt(n); i++) {
			massive.push_back(Data[info]);
			info++;
		}
		Dataa.push_back(massive);
		if (info > n) {
			break;
		}
	}
	output = Bozosort(Dataa);
	for(int i=0;i<n;i++){
		cout << output[i];
	}
	cout << endl;
	output = Bozosort(Dataa, false);
	for (int i = 0; i < n; i++) {
		cout << output[i];
	}
	cout << endl;
	int one = Data[0];
	int two = Data[1];
	int three = Data[2];
	vector<int>output2(3);
	output2=Bozosort(one, two, three);
	for (int i = 0; i < 3; i++) {
		cout << output2[i];
	}
	cout << endl;
	output2 = Bozosort(one, two, three,false);
	for (int i = 0; i < 3; i++) {
		cout << output2[i];
	}
	cout << endl;
}
