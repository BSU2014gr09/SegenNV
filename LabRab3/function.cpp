#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
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

void complex::operator=(double nmb)
{
	realPart = nmb;
	complexPart = 0;
}

complex operator/(const complex left, const complex right)
{
	double a = left.realPart;
	double b = left.complexPart;
	double c = right.realPart;
	double d = right.complexPart;
	return complex((a*c + b*d) / (c*c + d*d), (b*c - a*d) / (c*c + d*d));
}
complex operator/(const complex left, const double right)
{
	double a = left.realPart;
	double b = left.complexPart;
	return complex(a / right, b / right);
}
complex operator/(const double left, const complex right)
{
	double a = left;
	double c = right.realPart;
	double d = right.complexPart;
	return complex((a*c) / (c*c + d*d), (-a*d) / (c*c + d*d));
}

complex operator*(const complex left, const complex right)
{
	double a = left.realPart;
	double b = left.complexPart;
	double c = right.realPart;
	double d = right.complexPart;
	return complex((a*c - b*d), (b*c + a*d));
}
complex operator*(const complex left, const double right)
{
	double a = left.realPart;
	double b = left.complexPart;
	return complex(a * right, b * right);
}
complex operator*(const double left, const complex right)
{
	double c = right.realPart;
	double d = right.complexPart;
	return complex(left*c, left*d);
}

complex operator+(const double nmb1, const complex nmb2)
{
	double r = nmb1 + nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator+(const complex nmb1, const double nmb2)
{
	double r = nmb1.realPart + nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}
complex operator+(const complex nmb1, const complex nmb2)
{
	double r = nmb1.realPart + nmb2.realPart;
	double c = nmb1.complexPart + nmb2.complexPart;
	return complex(r, c);
}

complex operator-(const double nmb1, const complex nmb2)
{
	double r = nmb1 - nmb2.realPart;
	double c = nmb2.complexPart;
	return complex(r, c);
}
complex operator-(const complex nmb1, const complex nmb2)
{
	double r = nmb1.realPart - nmb2.realPart;
	double c = nmb1.complexPart - nmb2.complexPart;
	return complex(r, c);
}
complex operator-(const complex nmb1, const double nmb2)
{
	double r = nmb1.realPart - nmb2;
	double c = nmb1.complexPart;
	return complex(r, c);
}

bool operator==(const complex left, const complex right)
{
	bool r = (left.realPart == right.realPart);
	bool c = (left.complexPart == right.complexPart);
	return (r&&c);
}
bool operator!=(const complex left, const complex right)
{
	bool r = (left.realPart != right.realPart);
	bool c = (left.complexPart != right.complexPart);
	return (r||c);
}

double abs(const complex nmb)
{
	return sqrt(nmb.realPart*nmb.realPart + nmb.complexPart*nmb.complexPart);
}

complex conj(const complex nmb)
{
	return complex(nmb.realPart, -nmb.complexPart);
}

double arg(const complex z)
{
	const double pi = 3.14159265;
	double x = z.realPart;
	double y = z.complexPart;
	if (x > 0) return atan(y/x) * 180/pi;
	if (x < 0 && y >= 0) return (atan(y / x) + pi) * 180/pi;
	return (atan(y / x) - pi) * 180/pi;
}