// Lab 2B, Writing Templates And Overloading Operators
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
using namespace std;

#include "MoonJeongOokLab02bRoad.h"



int main()
{
	Road <double> r;

	cout << "\n**Showing pre-state values...\nValue of length for r is " << r.getLength();
	cout << "\nValue of width for r is " << r.getWidth() << endl;

	double width = 10;
	double length = .02;
	double thickness = 3.3;

	cout << "\n**Showing input values...\nInput of setLength() for r is " << length;
	cout << "\nInput of setWidth() for r is " << width;
	cout << "\nThickness for asphalt for r is " << thickness << endl;

	cout << "\n**Showing expected post-state values...\nValue of getLength() for r will be " << .02 << endl;
	cout << "Value of getWidth() for r will be " << 10 << endl;

	cout << "\n**Showing expected return value...\nValue of asphalt for r will be " << 290.4 << endl;

	r.setWidth(width);
	r.setLength(length); // setting both width and length

	cout << "\n**Showing actual post-state values...\nLength of r is " << r.getLength() << " miles" << endl;
	cout << "Width of r is " << r.getWidth() << " feet" << endl;
	cout << "\n**Showing actual return value...\nValue of asphalt for r is " << r.asphalt(thickness) << " cubic feet" << endl;

	Road <double> r2;

	double width2 = 20;
	double length2 = .04;
	double thickness2 = 4.4;

	cout << "\n**Showing input values...\nInput of setLength() for r2 is " << length2;
	cout << "\nInput of setWidth() for r2 is " << width2;
	cout << "\nThickness for asphalt for r2 is " << thickness2 << endl;

	r2.setWidth(width2);
	r2.setLength(length2); // setting both width and length

	cout << "\n**Showing actual post-state values...\nLength of r2 is " << r2.getLength() << " miles" << endl;
	cout << "Width of r2 is " << r2.getWidth() << " feet" << endl;
	cout << "\n**Showing actual return value...\nValue of asphalt for r2 is " << r2.asphalt(thickness2) << " cubic feet" << endl;

    cout << "\nIs the length (" << r2.getLength() << ") of r2 equal to r's length (" << r.getLength() << ")? " << endl;
	cout << boolalpha << (r==r2);

	cout << "\nIs the length ("<< r.getLength() << ") of r bigger than r2's length ("<< r2.getLength() << ")? " << endl;
	cout << boolalpha << (r2<r);

	cout << "\nIs the length (" << r2.getLength() << ") of r2 bigger than r's length (" << r.getLength() << ")? " << endl;
	cout << boolalpha << (r<r2);

	cout << "\n\n>>Making r2's values equal to r's..............." << endl;
	r2 = r;

	cout << "\n**Showing values of r and r2...\nLength of r is " << r.getLength() << " miles" << endl;
	cout << "Width of r is " << r.getWidth() << " feet" << endl;
	cout << "\nLength of r2 is " << r2.getLength() << " miles" << endl;
	cout << "Width of r2 is " << r2.getWidth() << " feet" << endl;

	cout << "\nIs the length (" << r2.getLength() << ") of r2 equal to r's length (" << r.getLength() << ")? " << endl;
	cout << boolalpha << (r==r2);

	cout << "\n\n>>Creating r3 to check whether int input values work" << endl;

	Road<int> r3;

	cout << "\n**Showing pre-state values...\nValue of length for r3 is " << r3.getLength();
	cout << "\nValue of width for r3 is " << r3.getWidth() << endl;

	int width3 = 30;
	int length3 = 2;
	int thickness3 = 3;

	cout << "\n**Showing input values...\nInput of setLength() for r3 is " << length3;
	cout << "\nInput of setWidth() for r3 is " << width3;
	cout << "\nThickness for asphalt for r3 is " << thickness3 << endl;

	cout << "\n**Showing expected post-state values...\nValue of getLength() for r3 will be " << 2 << endl;
	cout << "Value of getWidth() for r3 will be " << 30 << endl;

	cout << "\n**Showing expected return value...\nValue of asphalt for r3 will be " << 79200 << endl;

	r3.setWidth(width3);
	r3.setLength(length3); // setting both width and length

	cout << "\n**Showing actual post-state values...\nLength of r3 is " << r3.getLength() << " miles" << endl;
	cout << "Width of r3 is " << r3.getWidth() << " feet" << endl;
	cout << "\n**Showing actual return value...\nValue of asphalt for r3 is " << r3.asphalt(thickness) << " cubic feet" << endl;

	cout << "\nPress enter" << endl;
	cin.get();
}
