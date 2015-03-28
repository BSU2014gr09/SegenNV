#include<iostream>
#include"func.h"
using namespace std;

void initArr(int **a, int n, int m, ifstream &in)
{
	for (int j = 0; j < n; j++)
	{	
		for (int **i = a; i < a + m; i++)
			in >> *(*i+j);
	}
}

void printArr(int ** a, int n, int m, ofstream &out)
{
	for (int j = 0; j < n; j++)
	{
		for (int **i = a; i < a + m; i++)
			out << *(*i + j) << " ";
		out << endl;
	}
}

int amtZero(int * a, int n)
{
	int amt = 0;
	while (n--)
	{
		amt += (*a == 0);
		a++;
	}
	return amt;
}

void sortColumn(int ** a, int n, int m)
{
	for (int **i = a; i < a + m - 1; i++)
		for (int **j = i + 1; j < a + m; j++)
			if (amtZero(*i, n)>amtZero(*j, n)) swap(*i, *j);
}