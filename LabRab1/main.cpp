#include<iostream>
#include<conio.h>
#include"func.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const char * task = "37. В строке найти и вывести на экран все слова, в которых буквы упорядочены в порядке, обратном алфавитному (TOK, zona)";
	int n = 1000;
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
			cout << task << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		case 2:
		{
			system("cls");
			char * str = new char[n];
			printLexSubStr(str, n);
			delete[] str;
			cout << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a"; }
		break;
		default:
			system("cls");
			cout << "Error:\a \'" << (char)(choice + 48) << "\' undefined. ";
			cout << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		}
	} while (choice);
	//system("pause");
	return 0;
}