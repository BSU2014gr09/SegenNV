#include<iostream>
#include<cstring>
#include<new>
#include"src.h"

bool arrStr::setStr(int n)
{
	const int maxLength = 80;
	size = n;
	arr = new (std::nothrow) char * [size];
	if (!arr) return 1;
	char **p = arr;
	while (n--)
	{
		char * strTmp = new (std::nothrow) char[maxLength];
		if (!strTmp) return 1;
		std::cin.getline(strTmp, maxLength);
		*p = new (std::nothrow) char[strlen(strTmp)+1];
		if (!*p) return 1;
		strcpy(*p, strTmp);
		p++;
		delete[] strTmp;
	}
	return 0;
}

void arrStr::getStr()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

void arrStr::sort()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i; j < size; j++)
			if (amtWordNumb(arr[i]) > amtWordNumb(arr[j])) std::swap(arr[i], arr[j]);
}

int arrStr::amtWordNumb(char * str)
{
	int amtWord = 0;
	char * tmp = new char[strlen(str) + 1];
	strcpy(tmp, str);
	char * p = strtok(tmp, ",.; -!?");
	while (p)
	{
		int lengthWord = strlen(p), amtDig = 0;
		int l = lengthWord;
		while (lengthWord)
		{
			if(isdigit(*p)) amtDig++;
			p++;
			lengthWord--;
		}
		if(amtDig == l) amtWord++;
		p = strtok(NULL, ",.; -!?");
	}
	return amtWord;
}