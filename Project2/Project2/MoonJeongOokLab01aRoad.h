#ifndef MOONJEONGOOKLAB01AROAD_H
#define MOONJEONGOOKLAB01AROAD_H

#include <iostream>
using namespace std;

class Road
{
private:
	double length;
	double width; // attributes

public: // public interferce
	Road(); // constructor
	void setWidth(double); // mutator, width in feet, if the variable is less than 0, it will turn out to be 0 always.
	void setLength(double); // mutator, length in mile, if the variable is less than 0, it will turn out to be 0 always.
	double getWidth() const; // accessor, can access to value of width.
	double getLength() const; // accessor, can access to value of length.
	double asphalt(double); // accessor, accepting parameter in inch and calculating net asphalt needed in cubic feet.
};
#endif MOONJEONGOOKLAB01AROAD_H