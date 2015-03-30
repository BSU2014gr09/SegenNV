#include<iostream>
#include<iomanip>
#include"func.h"
using namespace std;

void initArr(float **a, int n, int m, ifstream &in)
{
	for (int j = 0; j < n; j++)
	{	
		for (float **i = a; i < a + m; i++)
			in >> *(*i+j);
	}
}

void printArr(float ** a, int n, int m, ofstream &out)
{
	//out.width(2);
	for (int j = 0; j < n; j++)
	{
		for (float **i = a; i < a + m; i++)
			out<<setw(4) << *(*i + j) << " ";
		out << endl;
	}
}

int amtZero(float * a, int n)
{
	int amt = 0;
	while (n--)
	{
		amt += (*a == 0);
		a++;
	}
	return amt;
}

void sortColumn(float ** a, int n, int m)
{
	for (float **i = a; i < a + m - 1; i++)
		for (float **j = i + 1; j < a + m; j++)
			if (amtZero(*i, n)>amtZero(*j, n)) swap(*i, *j);
}