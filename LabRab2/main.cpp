#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<new>
#include"func.h"
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	setlocale(LC_ALL, "Rus");
	const char * task = "59. В массиве А(N,M) расположить столбцы в порядке возрастания количества нулевых элементов в каждом столбце. Указатели на столбцы.";
	int n, m;
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
			cout << "Прочитал n. \n";
			in >> n;
			cout << "Прочитал m. \n";
			in >> m;
			if (n < 0 || m < 0){
				out << "Ошибка: Размеры матрицы не могут быть отрицательными.";
				return 1;
			}
			float ** arr = new float *[m];
			for (float ** i = arr; i < arr + m; i++)
			{
				*i = new float[n];
			}
			initArr(arr, n, m, in);
			sortColumn(arr, n, m);
			printArr(arr, n, m, out);
			for (float ** i = arr; i < arr + m; i++)
				delete[] * i;
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
	return 0;
}