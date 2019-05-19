#include "MoonJeongOokLab01bTime.h"

Time::Time()
{
	hours = 0.0;
	minutes = 0.0;
	seconds = 0.0;
} // setting initial values for each member

void Time::setHours(double a)
{
	if (a < 0)
		hours = 0;
	else
		hours = a;
} // setting hours from input

void Time::setMinutes(double a)
{
	if (a < 0)
		minutes = 0;
	else
		minutes = a;
} // setting minutes from input

void Time::setSeconds(double a)
{
	if (a < 0)
		seconds = 0;
	else
		seconds = a;
} // setting minutes from input

double Time::timeInHours() const  /// accessor
{
	return hours + (minutes / 60) + (seconds / 3600);
} // showing hours

double Time::timeInMinutes() const  /// accessor
{
	return (hours * 60) + minutes + (seconds / 60);
} // showing minutes

double Time::timeInSeconds() const  /// accessor
{
	return (hours * 3600) + (minutes * 60) + seconds;
} // showing seconds

bool operator<(const Time& a, const Time& b)
{
	if (a.timeInSeconds()<b.timeInSeconds()) 
	{ 
		cout << "True" << endl;
		return true;
	}
		
	if (a.timeInSeconds()>b.timeInSeconds())
	{
		cout << "False" << endl;
		return false;
	}
	if (a.timeInSeconds() == b.timeInSeconds())
	{
		cout << "They are equal to each other" << endl;
		return false;
	}
	
}