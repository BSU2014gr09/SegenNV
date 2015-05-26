//7. ќтсортировать строки по количеству слов по количеству слов, состо€щих только из цифр.
#include<iostream>
#include"src.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	arrStr text;
	int n;
	cout << "¬ведите колличество строк.\n";
	cin >> n;
	fflush(stdin);
	if (text.setStr(n))
	{
		cout << "Error: no memory!\n";
		system("pause");
		return 0;
	}
	cout << "¬ведите 1, если хотите отсортировать по возрастанию\n";
	cout << "¬ведите 0, если хотите отсортировать по возрастанию\n";
	bool r;
	cin >> r;
	text.sort(r);
	text.getStr();
	system("pause");
	return 0;
}