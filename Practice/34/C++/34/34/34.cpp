#include <iostream>
using namespace std;

void create(int* *a, int size,int first=0,int step=0) {
	*a = new int[size];
	int count = first;
	(*a)[0] = count;
	for (int i = 1; i < size; i++) {
		count += step;
		(*a)[i] = count;
	}
}
void destroy(int **a=nullptr){
	if (*a == nullptr) {}
	else {
		delete [] *a;
		*a == nullptr;
	}
}
int* sort(int* a, int size) {
		int counter = 0;
		for (int i = 1; i < size; i++) {
			for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
				counter++;
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
		return a;
}

int* print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << "  ";
	}
	return a;
}
int main()
{
	int size, first, step;
	cin >> size >> first >> step;
	int* a;
	create(&a, size, first, step);
	sort(a, size);
	print(a, size);
	destroy(&a);
}