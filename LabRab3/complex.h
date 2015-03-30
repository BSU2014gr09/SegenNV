#pragma once
#include<iostream>
struct complex
{
	private:
		double complexPart;
		double realPart;
	public:
		complex(double real, double complex) : realPart(real), complexPart(complex)
			{}
		complex() : realPart(0), complexPart(0)
			{}
		complex(double real) : realPart(real), complexPart(0)
			{}
		friend std::ostream& operator<< (std::ostream&, complex);
		friend complex operator>> (std::istream&, complex&);
		void operator=(double);
		void operator+=(complex);
		void operator+=(double);
		void operator-=(complex);
		void operator-=(double);
		void operator*=(complex);
		void operator*=(double);
		void operator/=(complex);
		void operator/=(double);
		complex operator*(complex);
		complex operator*(double);
		complex operator/(complex);
		complex operator/(double);
		friend complex operator+(double, complex);
		friend complex operator-(double, complex);
		friend complex operator+(complex, complex);
		friend complex operator-(complex, complex);
		friend complex operator+(complex, double);
		friend complex operator-(complex, double);
		bool operator==(complex);
		friend double abs(complex);
		friend complex conj(complex);
};