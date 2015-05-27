#include<iostream>
#include<cstdlib>
#include<cmath>
#include"stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	stack PRN;
	int n = 100;
	while (1){
		char * str = new char[n];
		cin.getline(str, n);
		//cout << str;
		char * ptrEnd;
		char * c = str;
		float tmp;
		while (*c)
		{
			if (*c == 0)  break;
			switch (*c)
			{
			case '+':
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp = PRN.pop();
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp += PRN.pop();
				PRN.push(tmp);
				c++;
				break;
			case '-':
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp = PRN.pop();
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				PRN.push(PRN.pop() - tmp);
				c++;
				break;
			case '*':
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp = PRN.pop();
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp *= PRN.pop();
				PRN.push(tmp);
				c++;
				break;
			case '/':
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp = PRN.pop();
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				PRN.push(PRN.pop() / tmp);
				c++;
				break;
			case '^':
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				tmp = PRN.pop();
				if (PRN.isEmpty())
				{
					cout << "Ошибка: неверное выражение!\n";
					goto Err;
				}
				PRN.push(pow(PRN.pop() , tmp));
				c++;
				break;
				/*case '%':
					tmp = PRN.pop();
					tmp %= PRN.pop();
					PRN.push(tmp);
					c++;
					break;*/
			}
			float nmb = strtod(c, &ptrEnd);
			if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '^') c--;
			if (nmb == 0 && *c != '0') { c++; continue; }
			PRN.push(nmb);
			c = ptrEnd;
		}
		cout << "Результат выражения равен " << PRN.pop() << endl;
Err:		delete[] str;
	}
	
	/*char k;
	do{
		cin >> k;
		if (k>=48 && k<=57) PRN.push(k);
		else 
	}*/
	system("pause");
	return 0;
}