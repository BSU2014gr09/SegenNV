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

double complex::abs(const complex nmb)
{
	return sqrt(nmb.realPart*nmb.realPart + nmb.complexPart*nmb.complexPart);
}

complex complex::conj(const complex nmb)
{
	nmb.complexPart *= -1;
	return nmb;
}

double complex::arg(const complex z)
{
	const double pi = 3.14159265;
	double x = z.realPart;
	double y = z.complexPart;
	if (x > 0) return atan(y / x) * 180 / pi;
	if (x < 0 && y >= 0) return (atan(y / x) + pi) * 180 / pi;
	return (atan(y / x) - pi) * 180 / pi;
}

ostream& operator<< (ostream& out, const complex nmb)
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

void complex::operator=(const double nmb)
{
	realPart = nmb;
	complexPart = 0;
}

void complex::operator+=(const complex nmb)
{
	*this = *this + nmb;
}

void complex::operator+=(const double nmb)
{
	realPart += nmb;
}

void complex::operator-=(const complex nmb)
{
	*this = *this - nmb;
}

void complex::operator-=(const double nmb)
{
	realPart -= nmb;
}

void complex::operator*=(const complex nmb)
{
	/*double r = realPart;
	double c = complexPart;
	realPart = r * nmb.realPart - c * nmb.complexPart;
	complexPart = r * nmb.complexPart - c * nmb.realPart;*/
	*this = *this*nmb;
}

void complex::operator*=(const double nmb)
{
	*this = *this*nmb;
}

void complex::operator/=(const complex nmb)
{
	*this = *this / nmb;
}

void complex::operator/=(const double nmb)
{
	*this = *this / nmb;
}

complex complex::operator*(const complex nmb)
{
	double r = realPart * nmb.realPart - complexPart * nmb.complexPart;
	double c = complexPart * nmb.realPart + realPart * nmb.complexPart;
	return complex(r, c);
}

complex complex::operator*(const double nmb)
{
	double r = realPart*nmb;
	double c = complexPart*nmb;
	return complex(r, c);
}

complex complex::operator/(const complex nmb)
{
	return *this*conj(nmb)/(abs(nmb)*abs(nmb));
}

complex complex::operator/(const double nmb)
{
	return complex(realPart / nmb, complexPart / nmb);
}

complex operator+(const double nmb1, const complex nmb2)
{
	double r = nmb1 + nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator-(const double nmb1, const complex nmb2)
{
	double r = nmb1 - nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator+(const complex nmb1, const complex nmb2)
{
	double r = nmb1.realPart + nmb2.realPart;
	double c = nmb1.complexPart + nmb2.complexPart;
	return complex(r, c);
}
complex operator-(const complex nmb1, const complex nmb2)
{
	double r = nmb1.realPart - nmb2.realPart;
	double c = nmb1.complexPart - nmb2.complexPart;
	return complex(r, c);
}
complex operator+(const complex nmb1, const double nmb2)
{
	double r = nmb1.realPart + nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}
complex operator-(const complex nmb1, const double nmb2)
{
	double r = nmb1.realPart - nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}

bool complex::operator==(const complex nmb)
{
	bool r = (realPart == nmb.realPart);
	bool c = (complexPart == nmb.complexPart);
	return (r&&c);
}
bool complex::operator!=(const complex nmb)
{
	bool r = (realPart == nmb.realPart);
	bool c = (complexPart == nmb.complexPart);
	return !(r&&c);
}