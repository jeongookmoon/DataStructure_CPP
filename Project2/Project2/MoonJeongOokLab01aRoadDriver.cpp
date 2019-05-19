// Lab 1a, Class Programming And Testing
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
using namespace std;

#include "MoonJeongOokLab01aRoad.h"



int main()
{
	Road r; // defining class object

	cout << "\n**Showing pre-state values...\nValue of length is " << r.getLength();
	cout << "\nValue of width is " << r.getWidth() << endl;

	double width = 10;
	double length = .02;
	double thickness = 3.3;

	cout << "\n**Showing input values...\nInput of setLength() is " << length;
	cout << "\nInput of setWidth() is " << width;
	cout << "\nThickness for asphalt is " << thickness << endl;

	cout << "\n**Showing expected post-state values...\nValue of getLength() will be " << .2 << endl;
	cout << "Value of getWidth() will be " << 10 << endl;

	cout << "\n**Showing expected return value...\nValue of asphalt will be " << 290.4 << endl;

	r.setWidth(10);
	r.setLength(.02); // setting both width and length

	cout << "\n**Showing actual post-state values...\nLength is " << r.getLength() << " miles" << endl;
	cout << "Width is " << r.getWidth() << " feet" << endl;

	cout << "\n**Showing actual return value...\nValue of asphalt is " << r.asphalt(thickness) << " cubic feet" << endl;

	// Object copy testing
	const Road r2 = r; // confirming that r2's content match r's

	cout << "\n****************** Object copy testing r2 = r ***********************" << endl;

	cout << "\nLength of r2 is " << r2.getLength() << " miles" << endl;
	cout << "Width of r2 is " << r2.getWidth() << " feet" << endl;

	cout << "\nValue of asphalt is " << r.asphalt(thickness) << " cubic feet" << endl;

	// Object copy testing
	Road r3 = r; // confirming that r3's content match r's

	cout << "\n****************** Object assignment testing r3 = r ***********************" << endl;

	cout << "\nLength of r3 is " << r3.getLength() << " miles" << endl;
	cout << "Width of r3 is " << r3.getWidth() << " feet" << endl;

	cout << "\nValue of asphalt is " << r3.asphalt(thickness) << " cubic feet" << endl;

	cout << "Press enter " << endl;
	cin.get();
}
