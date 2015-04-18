#pragma once
#include<iostream>
struct complex
{
		double complexPart;
		double realPart;
		complex(double real, double complex) : realPart(real), complexPart(complex)
			{}
		complex() : realPart(0), complexPart(0)
			{}
		complex(double real) : realPart(real), complexPart(0)
			{}
		void operator=(double);
};

std::ostream& operator<< (std::ostream&, complex);
complex operator>> (std::istream&, complex&);

complex operator*(const complex, const complex);
complex operator*(const complex, const double);
complex operator*(const double, const complex);

complex operator+(const double, const complex);
complex operator+(const complex, const complex);
complex operator+(const complex, const double);

complex operator-(const double, const complex);
complex operator-(const complex, const double);
complex operator-(const complex, const complex);

complex operator/(const complex, const complex);
complex operator/(const double, const complex);
complex operator/(const complex, const double);

bool operator==(const complex, const complex);
bool operator!=(const complex, const complex);

double abs(const complex);
complex conj(const complex);
double arg(const complex);