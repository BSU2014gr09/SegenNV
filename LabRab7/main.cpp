#include<iostream>
#include<fstream>
#include<memory>
#include"passengers.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Passenger * arrPass = nullptr;
	int n;
	int choice;
	do{
		system("cls");
		cout << "Чтобы ввести данные пассажиров, нажмите 1\n";
		cout << "Чтобы вывести список пассажироав в алфавитном порядке, нажмите 2\n";
		cout << "Чтобы определить пассажира с найбольшим(найменьшим) колличеством мест багажа, нажмите 3\n";
		cout << "Чтобы определить, имееться ли пассажир, багаж которого состоит из одной еденицы весом более 20кг, нажмите 4\n";
		cout << "Чтобы выйти, нажмите 0\n";
		cin >> choice;
		switch (choice){
		case 1:
			{
				system("cls");
				ifstream in("in.txt");
				if (!in.is_open())
				{
					cout << "Ошибка: неудалось открыть файл!\n";
					system("pause");
					break;
				}
				delete[] arrPass;
				in >> n;
				arrPass = new(std::nothrow) Passenger[n];
				if (!arrPass)
				{
					cout << "Ошибка: недостаточно памяти!\n";
					system("pause");
					break;
				}
				for (int i = 0; i < n; i++)
				{
					in >> arrPass[i];
				}
				in.close(); 
				cout << "Данные успешно загружены.\n";
				system("pause");
			}
			break;
		case 2:
			system("cls");
			sort(arrPass, arrPass + n - 1);
			for (int i = 0; i < n; i++)
				cout << arrPass[i];
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Пассажир с максимальным колличеством багажа: " << getName(findMaxPassenger(arrPass, n)) << endl;
			system("pause");
			break;
		case 4:
			if (moreThan20(arrPass, n)) cout << "Такой пассажир имеется.\n";
			else cout << "Такого пассажира нет.\n";
			system("pause");
			break;
		case 0: break;
		default:
			system("cls");
			cout << "Ошибка, попробуйте еще раз.\n";
			system("pause");
		}
	} while (choice);
	delete[] arrPass;
	//system("pause");
	return 0;
}