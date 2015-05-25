#include<iostream>
#include"src.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	arrStr text;
	int n = 4;
	if (text.setStr(n))
	{
		cout << "Error: no memory!\n";
		system("pause");
		return 0;
	}
	text.sort();
	text.getStr();
	system("pause");
	return 0;
}