#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

void clearBoof()
{
	cin.clear();
	while (cin.get() != '\n');
}

void initArr(char * str, int n)
{
	cin.getline(str, n);
}

void printArr(char * str)
{
	cout << str<<endl;
}

bool isLexicographical(char * str)
{
	str++;
	while (*(str - 1) > *str && *str) str++;
	return !(*str);
}

void printLexSubStr(char * str, int n)
{
	cout << "Enter string: \n";
	initArr(str, n);
	//clearBoof();
	char * subStr = strtok(str, " ,.!-"); //разбиваем строку на слова
	while (subStr)
	{
		if (isLexicographical(subStr)) printArr(subStr); //проверяем, подходит ли нам слово, если да, то вывводим
		subStr = strtok(NULL, " ,.!-"); //переходим к следующемц слову
	}
}

void interface(const char * task, int max_n)
{
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
			char * str = new char[max_n]; //выделяем память на строку максимальной длинны
			printLexSubStr(str, max_n); //выполняем задание
			delete[] str; //очищаем память
			cout << "Press Backspace to back in menu."; 
			while (_getch() != 8) cout << "\a"; } //пока не нажата Backspace, не выходим в меню
		break;
		default:
			system("cls");
			cout << "Error:\a \'" << (char)(choice + 48) << "\' undefined. "; //сообщение об ошибке
			cout << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		}
	} while (choice);
}
