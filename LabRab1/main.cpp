#include<iostream>
#include"func.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const char * task = "37. ¬ строке найти и вывести на экран все слова, в которых буквы упор€дочены в пор€дке, обратном алфавитному (TOK, zona)"; //условие задачи
	int max_n=1000;
	interface(task, max_n);
	//system("pause");
	return 0;
}