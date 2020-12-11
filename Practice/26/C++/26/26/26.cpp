#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;

/*template <class T>
void out(std::vector<T> end) {
	std::cout << std::endl;
	for (int i = 0; i < end.size(); i++) {
		std::cout << end[i] << " ";
	}
}*/
template <class T>
vector<T>Bozosort(vector<T>Data, bool sign = true) {
	bool ch = false;
	while (!ch) {
		int i1 = rand() % Data.size();
		int i2 = rand() % Data.size();
		T sw = Data[i1];
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

template <class T>
vector <T>Bozosort(vector<vector<T> > Data, bool sign = true) {
	vector<T>Two;
	for (int i = 0; i < Data.size(); i++) {
		for (int j = 0; j < Data.size(); j++) {
			Two.push_back(Data[i][j]);
		}
	}
	if (sign) {
		return Bozosort(Two);
	}
	if (!sign) {
		return Bozosort(Two, false);
	}
}

template <class T>
vector <T>Bozosort(T one, T two, T three, bool signe = true) {
	bool gg = false;
	vector <T>func(3);
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


int main() {
	srand(time(0));
	//кол-во чисел
	int n;
	//Ввод кол-ва чисел
	cin >> n;
	//вектор для первой функции
	vector<double>Data(n);
	//заполнение первого вектора
	for (int i = 0; i < n; i++) {
		cin >> Data[i];
	}
	//вывод первой функции
	vector<double>output(Data.size());
	output = Bozosort(Data);
	//при тру
	for (int i = 0; i < Data.size(); i++) {
		cout << output[i];
	}
	cout << endl;
	output = Bozosort(Data, false);
	// при фолс
	for (int i = 0; i < Data.size(); i++) {
		cout << output[i];
	}
	cout << endl;
	int info = 0;
	vector<vector<double>>Dataa;
	for (int i = 0; i < sqrt(n); i++) {
		std::vector<double> massive;
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
	for (int i = 0; i < n; i++) {
		cout << output[i];
	}
	cout << endl;
	output = Bozosort(Dataa, false);
	for (int i = 0; i < n; i++) {
		cout << output[i];
	}
	cout << endl;
	double one = Data[0];
	double two = Data[1];
	double three = Data[2];
	vector<double>output2;
	output2 = Bozosort(one, two, three);
	for (int i = 0; i < 3; i++) {
		cout << output2[i];
	}
	cout << endl;
	output2 = Bozosort(one, two, three, false);
	for (int i = 0; i < 3; i++) {
		cout << output2[i];
	}
	cout << endl;








	int n1;
	cin >> n1;
	//вектор для первой функции
	vector<string>Data1(n);
	//заполнение первого вектора
	for (int i = 0; i < n; i++) {
		cin >> Data1[i];
	}
	//вывод первой функции
	vector<string>output1(Data1.size());
	output1= Bozosort(Data1);
	//при тру
	for (int i = 0; i < Data1.size(); i++) {
		cout << output1[i];
	}
	cout << endl;
	output1 = Bozosort(Data1, false);
	// при фолс
	for (int i = 0; i < Data1.size(); i++) {
		cout << output1[i];
	}
	cout << endl;
	int info1 = 0;
	vector<vector<string>>Dataa1;
	for (int i = 0; i < sqrt(n1); i++) {
		std::vector<string> massive1;
		for (int i = 0; i < sqrt(n1); i++) {
			massive1.push_back(Data1[info1]);
			info1++;
		}
		Dataa1.push_back(massive1);
		if (info1 > n1) {
			break;
		}
	}
	output1 = Bozosort(Dataa1);
	for (int i = 0; i < n1; i++) {
		cout << output1[i];
	}
	cout << endl;
	output1 = Bozosort(Dataa1, false);
	for (int i = 0; i < n1; i++) {
		cout << output1[i];
	}
	cout << endl;
	string one1 = Data1[0];
	string two1 = Data1[1];
	string three1 = Data1[2];
	vector<string>output21(3);
	output21 = Bozosort(one1, two1, three1);
	for (int i = 0; i < 3; i++) {
		cout << output21[i];
	}
	cout << endl;
	output21 = Bozosort(one1, two1, three1, false);
	for (int i = 0; i < 3; i++) {
		cout << output21[i];
	}
	cout << endl;
}