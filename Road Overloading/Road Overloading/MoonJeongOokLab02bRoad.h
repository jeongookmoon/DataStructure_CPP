#ifndef MOONJEONGOOKLAB02BROAD_H
#define MOONJEONGOOKLAB02BROAD_H

#include <iostream>
using namespace std;

template <class Datatype>
class Road
{
private:
	Datatype length;
	Datatype width; // attributes

public: // public interferce
	Road(); // constructor
	void setWidth(const Datatype&); // mutator
	void setLength(const Datatype&);
	Datatype getWidth() const; // accessor
	Datatype getLength() const;
	Datatype asphalt(const Datatype&)const;
};
template <class Datatype>
Road<Datatype>::Road()
{
	length =0.0, width = 0.0;
} // setting initial values for each member

template <class Datatype>
void Road<Datatype>::setWidth(const Datatype& a)
{
	if (a < 0)
		width = 0;
	else
		width = a;
} // setting width from input

template <class Datatype>
void Road<Datatype>::setLength(const Datatype& a)
{
	if (a < 0)
		length = 0;
	else
		length = a;
} // setting length from input

template <class Datatype>
Datatype Road<Datatype>::getWidth() const  /// accessor
{
	return width;
} // showing width

template <class Datatype>
Datatype Road<Datatype>::getLength() const  /// accessor
{
	return length;
} // showing length

template <class Datatype>
Datatype Road<Datatype>::asphalt(const Datatype& v) const
{
	return v * width * length * 5280 / 12;
} // accepting parameter in inch and calculating net asphalt needed in cubic feet.

template <class Datatype>
bool operator<(const Road<Datatype>& a, const Road<Datatype>& b) // definition, overloading function to check whether one is greater than the other or equal to the other
{
	if (a.getLength()<b.getLength())
	{
		//		cout << "True" << endl;
		return true;
	}
	return false;

}

template <class Datatype>
bool operator==(const Road<Datatype>& a, const Road<Datatype>& b) // definition, overloading function to check whether one is greater than the other or equal to the other
{
	if ((a.getLength() + a.getWidth()) == (b.getLength() + b.getWidth()))
	{
		//		cout << "They are equal to each other" << endl;
		return true;
	}
	return false;

}

#endif
