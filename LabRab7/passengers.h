#ifdef passengers_h
#define passengers_h

#include<iostream>

class Passenger
{
	private:
		char * name;
		float * weight;
		int sizeOfName;
		int nmbOfPlace;
	public:
		Passenger() : name(nullptr), weight(nullptr), sizeOfName(0), nmbOfPlace(0) {}
		friend std::ostream& operator<<(std::ostream&, const Passenger);
		friend Passenger operator>> (std::istream&, Passenger&);
		friend Passenger * findMaxPassenger(Passenger *, const int);
		friend void sort(Passenger *, Passenger *);
		friend bool moreThan20(Passenger *, int);
		friend char * getName(Passenger *);
};

#endif
