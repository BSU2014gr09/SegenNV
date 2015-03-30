#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<math.h>
#include"complex.h"
using namespace std;

/*complex::complex(double real=0, double complex=0)
{
	complexPart = complex;
	realPart = real;
}

complex::complex()
{
	complexPart = 0;
	realPart = 0;
}*/

ostream& operator<< (ostream& out, complex nmb)
{
	return out << "(" << nmb.realPart << ", " << nmb.complexPart << ")";
}

complex operator>> (istream& in, complex& nmb)
{
	//return in>> nmb.realPart>>nmb.complexPart;
	char * str = new char[100];
	in.getline(str,100);
	char * part = strtok(str, " ,)(");
	nmb.realPart = atof(part);
	part = strtok(NULL, " ,()");
	nmb.complexPart = atof(part);
	return nmb;
}

void complex::operator=(double nmb)
{
	realPart = nmb;
	complexPart = 0;
}

void complex::operator+=(complex nmb)
{
	realPart += nmb.realPart;
	complexPart += nmb.complexPart;
}

void complex::operator+=(double nmb)
{
	realPart += nmb;
}

void complex::operator-=(complex nmb)
{
	realPart -= nmb.realPart;
	complexPart -= nmb.complexPart;
}

void complex::operator-=(double nmb)
{
	realPart -= nmb;
}

void complex::operator*=(complex nmb)
{
	double r = realPart;
	double c = complexPart;
	realPart = r * nmb.realPart - c * nmb.complexPart;
	complexPart = r * nmb.complexPart - c * nmb.realPart;
}

void complex::operator*=(double nmb)
{
	realPart *= nmb;
	complexPart *= nmb;
}

void complex::operator/=(complex nmb)
{
	double r = realPart;
	double c = complexPart;
	realPart = (r * nmb.realPart + c * nmb.complexPart) / (r*r + c*c);
	complexPart = (c * nmb.complexPart - r * nmb.realPart) / (r*r + c*c);
}

void complex::operator/=(double nmb)
{
	realPart /= nmb;
	complexPart /= nmb;
}

complex complex::operator*(complex nmb)
{
	double r = realPart * nmb.realPart - complexPart * nmb.complexPart;
	double c = realPart * nmb.complexPart - complexPart * nmb.realPart;
	return complex(r, c);
}

complex complex::operator*(double nmb)
{
	double r = realPart*nmb;
	double c = complexPart*nmb;
	return complex(r, c);
}

complex complex::operator/(complex nmb)
{
	double r = (realPart * nmb.realPart + complexPart * nmb.complexPart) / (realPart*realPart + complexPart*complexPart);
	double c = (complexPart * nmb.complexPart - realPart * nmb.realPart) / (realPart*realPart + complexPart*complexPart);
	return complex(r, c);
}

complex operator+(double nmb1, complex nmb2)
{
	double r = nmb1 + nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator-(double nmb1, complex nmb2)
{
	double r = nmb1 - nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator+(complex nmb1, complex nmb2)
{
	double r = nmb1.realPart + nmb2.realPart;
	double c = nmb1.complexPart + nmb2.complexPart;
	return complex(r, c);
}
complex operator-(complex nmb1, complex nmb2)
{
	double r = nmb1.realPart - nmb2.realPart;
	double c = nmb1.complexPart - nmb2.complexPart;
	return complex(r, c);
}
complex operator+(complex nmb1, double nmb2)
{
	double r = nmb1.realPart + nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}
complex operator-(complex nmb1, double nmb2)
{
	double r = nmb1.realPart - nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}

bool complex::operator==(complex nmb)
{
	bool r = (realPart == nmb.realPart);
	bool c = (complexPart == nmb.complexPart);
	return (r&&c);
}

double abs(complex nmb)
{
	return sqrt(nmb.realPart*nmb.realPart + nmb.complexPart*nmb.complexPart);
}

complex conj(complex nmb)
{
	nmb.complexPart *= -1;
	return nmb;
}