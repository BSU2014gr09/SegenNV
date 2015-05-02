#include<iostream>
#include"complex.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	complex a(3, 2), b(2, 6);
	a /= b;
	cout << a;
	/*complex a[2],i(3,6), c;
	cout << i << endl;
	i = complex(3, 5);
	cout << i << endl;
	i = 4;
	cout << i << endl;
	for (int i = 0; i < 2; i++)
		cin >> a[i];//вводить нужно через enter.
	cout << endl;
	for (int i = 0; i < 2; i++)
		cout << a[i];
	c = a[0] / a[1];
	cout << c<<endl;
	c += a[0];
	cout << c<<endl;
	c *= a[1];
	cout << c<<endl;
	cout << abs(c)<<endl;
	cout << conj(c)<<endl;//сопряженное
	c = 4 + i;
	cout << c << endl;*/
	system("pause");
	return 0;
}