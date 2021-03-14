#include <iostream>
using namespace std;
int* create(int size, int first=0,int step=0) {
	int *array = new int[size];
	int veil = first;
	for (int i = 0; i < size; i++) {
		if (i > 0) {
			veil = veil + step;
			array[i] = veil;
		}
		else {
			array[i] = first;
		}
	}
	return array;
}
	

int* sort(int* array, int size) {
	int counter = 0;
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
			counter++;
			int tmp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = tmp;
		}
	}
	return array;
}

int * print(int size, int *array) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << array[i];
			break;
		}
		cout << array[i]<<",";
	}
	cout << "]";
	return array;
}

int main()
{
	int size;
	int first;
	int step;
	cin >> size;
	cin >> first;
	cin >> step;
	int *array = create(size, first, step);
	sort(array, size);
	print(size, array);

}
