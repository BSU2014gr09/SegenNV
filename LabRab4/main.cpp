#include<iostream>
#include<cstdlib>
#include"stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	stack PRN;
	int n = 100;
	while (1){
		char * str = new char[100];
		cin.getline(str, 100);
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
				tmp = PRN.pop();
				tmp += PRN.pop();
				PRN.push(tmp);
				c++;
				break;
			case '-':
				tmp = PRN.pop();
				PRN.push(PRN.pop() - tmp);
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
				PRN.push(PRN.pop() / tmp);
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
			if (nmb == 0 && *c != '0') { c++; continue; }
			PRN.push(nmb);
			c = ptrEnd;
		}
		cout << "Результат выражения равен " << PRN.pop() << endl;
		delete[] str;
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