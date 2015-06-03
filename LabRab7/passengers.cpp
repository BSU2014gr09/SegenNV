#include<iostream>
#include<cstring>
#include"passengers.h"
using namespace std;

ostream& operator<<(ostream& out, const Passenger humen)
{
	out << humen.name << endl;
	out << humen.nmbOfPlace << endl;
	for (int i = 0; i < humen.nmbOfPlace; i++)
		out << humen.weight[i] << " ";
	out << endl;
	return out;
}
Passenger operator>> (istream& in, Passenger& humen)
{
	char * tmpName = new char[80];
	in.ignore();
	in.getline(tmpName, 80);
	//in >> tmpName;
	humen.sizeOfName = strlen(tmpName) + 1;
	humen.name = new char[humen.sizeOfName];
	strcpy(humen.name, tmpName);
	delete[] tmpName;
	in >> humen.nmbOfPlace;
	humen.weight = new float[humen.nmbOfPlace];
	for (int i = 0; i < humen.nmbOfPlace; i++)
		in >> humen.weight[i];
	return humen;
}

void sort(Passenger * begin, Passenger * end)
{
	for (Passenger * i = begin; i < end; i++)
		for (Passenger * j = i + 1; j <= end; j++)
			if (stricmp(i->name,j->name)>0)
				swap(*i, *j);
}

Passenger * findMaxPassenger(Passenger * passenger, const int n)
{
	Passenger *max = passenger;
	for (int i = 1; i < n; i++)
	{
		max = (passenger[i].nmbOfPlace > max->nmbOfPlace) ? passenger + i : max;
	}
	return max;
}

bool moreThan20(Passenger * passenger, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (passenger[i].nmbOfPlace == 1 && passenger[i].weight[0] > 20) return true;
	}
	return false;
}

char * getName(Passenger * humen)
{
	return humen->name;
}