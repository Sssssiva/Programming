#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string a="",b, words[6] = { "hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen" };
	double d=1,f;
	cin >> b;
	for (int i = 0; i < 6; i++) {
		a += words[i];
		
	}
	for (int i = 0; i<(b.length());i++) {
		f=count(a.begin(), a.end(), b[i]);
		d *= (f / 45);
	}
	cout << d;
}

