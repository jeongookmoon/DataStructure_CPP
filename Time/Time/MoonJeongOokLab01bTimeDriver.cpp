// Lab 1b, Class Programming And Testing
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
using namespace std;

#include "MoonJeongOokLab01bTime.h"


int main()
{
	Time t1;
	
	cout << "\n**Showing pre-state values...\nValue of hours is " << t1.timeInHours() << endl;
	cout << "Value of minutes is " << t1.timeInMinutes() << endl;
	cout << "Value of seconds is " << t1.timeInSeconds() << endl;
	
	double hours = 1;
	double minutes = 40;
	double seconds = 30;

	cout << "\n**Showing input values...\nInput of setHours() is "<< hours << endl;
	cout << "Input of setMinutes() is " << minutes << endl;
	cout << "Input of setSeconds() is " << seconds << endl;
	
	cout << "\n**Showing expected post-state values or return values...\nValue of getHours() will be " << 1.675 << endl;
	cout << "Value of getMinutes() will be " << 100.5 << endl;
	cout << "Value of getSeconds() will be " << 6030 << endl;
	
	t1.setHours(1);
	t1.setMinutes(40);
	t1.setSeconds(30);

    cout << "\n**Showing actual post-state values or return values...\nTime in Hours is " << t1.timeInHours() << " hours" << endl;
	cout << "Time in Minutes is " << t1.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds is " << t1.timeInSeconds() << " seconds" << endl;
	
	// Object copy testing
	const Time t2 = t1; // confirming that r2's content match r's
	
	cout << "\n****************** Object copy testing t2 = t1 ***********************" << endl;
	
	cout << "\nTime in Hours of t2 is " << t2.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t2 is " << t2.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t2 is " << t2.timeInSeconds() << " seconds" << endl;
	
	Time t3 = t1; // confirming that r2's content match r's


	cout << "\n****************** Object assignment testing t3 = t1 ***********************" << endl;

	cout << "\nTime in Hours of t3 is " << t3.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t3 is " << t3.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t3 is " << t3.timeInSeconds() << " seconds" << endl;

	cout << "Press enter " << endl;
	cin.get();
}
