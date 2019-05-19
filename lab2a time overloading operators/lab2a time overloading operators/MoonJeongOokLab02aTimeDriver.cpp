// Lab 2a, Writing Overloading Operators
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
using namespace std;

#include "MoonJeongOokLab02aTime.h"


int main()
{
	Time t1, t2;

	double hours = 1;
	double minutes = 40;
	double seconds = 30;

	cout << "\nInput of setHours() for t1 is " << hours << endl;
	cout << "Input of setMinutes() for t1 is " << minutes << endl;
	cout << "Input of setSeconds() for t1 is " << seconds << endl;

	t1.setHours(1);
	t1.setMinutes(40);
	t1.setSeconds(30);

	cout << "\nTime in Hours of t1 is " << t1.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t1 is " << t1.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t1 is " << t1.timeInSeconds() << " seconds" << endl;

	double hours2 = 2;
	double minutes2 = 50;
	double seconds2 = 40;

	cout << "\nInput of setHours() for t2 is " << hours2 << endl;
	cout << "Input of setMinutes() for t2 is " << minutes2 << endl;
	cout << "Input of setSeconds() for t2 is " << seconds2 << endl;

	t2.setHours(2);
	t2.setMinutes(50);
	t2.setSeconds(40);

	cout << "\nTime in Hours of t2 is " << t2.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t2 is " << t2.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t2 is " << t2.timeInSeconds() << " seconds" << endl;

	cout << "\nIs t1 equal to t2?";
	cout << "\nAnswer is .... ";
	cout << boolalpha << (t2 == t1); // calling the function // boolalpha print 'true' for true and 'false' for false

	cout << "\nComparing the total time in seconds between t2 and t1..... \nIs t1 smaller than t2?";
	cout << "\nAnswer is .... ";
	cout << boolalpha << (t1<t2); // calling the function // boolalpha print 'true' for true and 'false' for false

	cout << "\nIs t1 greater than t2?";
	cout << "\nAnswer is .... ";
	cout << boolalpha << (t2<t1); // calling the function // boolalpha print 'true' for true and 'false' for false

	t2.setHours(1);
	t2.setMinutes(40);
	t2.setSeconds(30);

	cout << "\n\n**Changing t2 values to be equal to t1...\nTime in Hours of t2 is " << t2.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t2 is " << t2.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t2 is " << t2.timeInSeconds() << " seconds" << endl;

	cout << "\nTime in Hours of t1 is " << t1.timeInHours() << " hours" << endl;
	cout << "Time in Minutes of t1 is " << t1.timeInMinutes() << " minutes" << endl;
	cout << "Time in Seconds of t1 is " << t1.timeInSeconds() << " seconds" << endl;

	cout << "\nIs t1 equal to t2?";
	cout << "\nAnswer is .... ";
	cout << boolalpha << (t2==t1); // calling the function // boolalpha print 'true' for true and 'false' for false

	cout << "\nPress enter " << endl;
	cin.get();
}
