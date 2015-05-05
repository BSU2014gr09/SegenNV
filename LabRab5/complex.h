#pragma once
#include<iostream>
class complex
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

		friend std::ostream& operator<< (std::ostream&, const complex);
		friend complex operator>> (std::istream&, complex&);

		void operator=(const double);
		void operator+=(const complex);
		void operator+=(const double);
		void operator-=(const complex);
		void operator-=(const double);
		void operator*=(const complex);
		void operator*=(const double);
		void operator/=(const complex);
		void operator/=(const double);
		complex operator*(const complex);
		complex operator*(const double);
		complex operator/(const complex);
		complex operator/(const double);
		friend complex operator+(const double, const complex);
		friend complex operator-(const double, const complex);
		friend complex operator+(const complex, const complex);
		friend complex operator-(const complex, const complex);
		friend complex operator+(const complex, const double);
		friend complex operator-(const complex, const double);
		bool operator==(const complex);
		bool operator!=(const complex);
		double abs(const complex);
		complex conj(const complex);
		double arg(const complex);
};
