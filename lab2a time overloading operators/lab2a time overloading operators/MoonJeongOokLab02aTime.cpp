#include "MoonJeongOokLab02aTime.h"

Time::Time()
{
	hours = 0.0;
	minutes = 0.0;
	seconds = 0.0;
} // setting initial values for each member

void Time::setHours(const double& a)
{
	if (a < 0)
		hours = 0;
	else
		hours = a;
} // setting hours from input

void Time::setMinutes(const double& a)
{
	if (a < 0)
		minutes = 0;
	else
		minutes = a;
} // setting minutes from input

void Time::setSeconds(const double& a)
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

bool operator<(const Time& a, const Time& b) // definition, overloading function to check whether one is greater than the other or equal to the other
{
	if (a.timeInSeconds()<b.timeInSeconds())
	{
//		cout << "True" << endl;
		return true;
	}
    return false;
}

bool operator==(const Time& a, const Time& b) // definition, overloading function to check whether one is greater than the other or equal to the other
{
	if (a.timeInSeconds()==b.timeInSeconds())
	{
		return true;
	}
    return false;
}
