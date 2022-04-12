#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int nod(int n, int m) 
{
	if (m == 0)
		return n;
	if (n > m)
		return nod(m, n - m);
	else
		return nod(n, m - n);
}
int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0; int p = 0; int count; int i = 0; int w = 0; int m = 0; int nod1;
	int v[50]; 
	int z[50];
	string q;
	cout << "введите количество чисел: ";
	cin >> count;
	for (i; i < count; i++) {  
		cout << "введите число #" << i + 1 << ":  ";
		cin >> z[i];
	}
	ofstream x; 
	x.open("myfile.txt");
	if (!x.is_open()) {
		cout << "error" << endl;
	}
	else {
		for (w; w < count; w++) {
			x << z[w] << " ";
		}
	}
	cout << "все числа записаны в файл myfile.txt";
	x.close(); 
	ifstream y; 
	y.open("myfile.txt");
	if (!y.is_open()) {
		cout << "error" << endl;
	}
	else {
		while (!y.eof()) {
			y >> v[n];
			n++;
		}
	}
	y.close(); 
	for (n; n < count; n++) { 
		cout << v[n];
	}
	for (i; i < count; i++) {
	}
	if (count >= 2) {
		nod1 = nod(v[0], v[1]);
	}
	else {
		nod1 = v[0];
	}
	for (int i = 2; i < count; i++) {
		nod1 = nod(nod1, v[i]);
	}
	cout << endl;
	cout << "наибольший общий делитель = " << nod1;
	cout << endl;
	for (int i = 0; i < 50; i++) 
	{
		for (int j = 2; j <= v[i] / 2; j++)
		{
			if (v[i] % j == 0 && v[i] != j)
			{
				v[i] = 0;
				break;
			}
		}
		if (v[i] > 0)
		{
			p++;
		}
	}
	cout << "количество простых чисел = " << p;
	cout << endl;
	ofstream t;
	t.open("myfile2.txt");
	if (!t.is_open()) { 
		cout << "error" << endl;
	}
	else {
		for (m; m < 50; m++) {
			if (v[m] > 0) {
				t << v[m] << " ";
			}
		}
	}
	t.close();
	cout << "простые числа записаны в файл myfile2.txt";
	cout << endl;
	system("pause");
	return 0;
}