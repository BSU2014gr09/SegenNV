#include<iostream>
#include<cstdlib>
#include"stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	stack PRN; //нужно RPN, но я перепутал
	//int n = 100;
	char * c = "4,6 8,9 + 2 * 7,9 4 6,5 - / -";
	char * ptrEnd;
	float tmp;
	while (*c)
	{
		if (*c == 0)  break; 
		switch (*c)
		{
		case '+':
			tmp = PRN.pop();
			tmp += PRN.pop();
			PRN.push(tmp);
			c++;
			break;
		case '-':
			tmp = PRN.pop();
			PRN.push(PRN.pop()-tmp);
			c++;
			break;
		case '*':
			tmp = PRN.pop();
			tmp *= PRN.pop();
			PRN.push(tmp);
			c++;
			break;
		case '/':
			tmp = PRN.pop();
			PRN.push(PRN.pop()/tmp);
			c++;
			break;
		/*case '%':
			tmp = PRN.pop();
			tmp %= PRN.pop();
			PRN.push(tmp);
			c++;
			break;*/
		}
		float nmb = strtod(c, &ptrEnd);  //ищем в строке число
		if (nmb == 0 && *c != '0') { c++; continue; } //если функция выдала 0, то проверяем что это, и, если ерунда какая-то, а не ноль, то в начало цикла
		PRN.push(nmb);
		c = ptrEnd;
	}
	cout << "Результат выражения равен " << (float)PRN.pop() << " " << (4.6 + 8.9) * 2 - 7.9 / (4 - 6.5)<<endl; //исходное выражение в нормальном виде для проверки
	
	/*char k;
	do{
		cin >> k;
		if (k>=48 && k<=57) PRN.push(k);
		else 
	}*/
	system("pause");
	return 0;
}