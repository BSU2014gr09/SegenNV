#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
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
	char * subStr = strtok(str, " ,.!-");
	while (subStr)
	{
		if (isLexicographical(subStr)) printArr(subStr);
		subStr = strtok(NULL, " ,.!-");
	}
}