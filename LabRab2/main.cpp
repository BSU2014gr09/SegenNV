#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include"func.h"
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	setlocale(LC_ALL, "Rus");
	const char * task = "59. В массиве А(N,M) расположить столбцы в порядке возрастания количества нулевых элементов в каждом столбце. Указатели на столбцы.";
	int n,m;
	int choice;
	do{
		system("cls");
		cout << "Press 1 to show task\n";
		cout << "Press 2 to run task\n";
		cout << "Press 0 to exit\n";
		choice = _getch() - 48;
		switch (choice)
		{
		case 0: break;
		case 1:
			system("cls");
			cout << task << endl << "\nPress Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		case 2:
		{
			system("cls");
			cout << "Enter N: ";
			in >> n;
			cout << "Enter M: ";
			in >> m;
			int ** arr = new int * [m];
			if (!arr)
			{
				cout << "Error. No memory!!!\n";
				system("pause");
				return 0;
			}
			for (int ** i = arr; i < arr + m; i++)
			{
				*i = new int[n];
				if (!*i)
				{
					cout << "Error. No memory!!!\n";
					system("pause");
					return 0;
				}
			}
			initArr(arr, n, m, in);
			sortColumn(arr, n, m);
			printArr(arr, n, m, out);
			for (int ** i = arr; i < arr + m; i++)
				delete[] *i;
			delete[] arr;
			cout << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a"; }
		break;
		default:
			system("cls");
			cout << "Error!!!\a";
			cout << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		}
	} while (choice);
	in.close();
	out.close();
	system("pause");
	return 0;
}