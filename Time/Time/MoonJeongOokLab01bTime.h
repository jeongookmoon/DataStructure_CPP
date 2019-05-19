#ifndef MOONJEONGOOKLAB01BTIME_H
#define MOONJEONGOOKLAB01BTIME_H
#include <queue>
#include <iostream>
using namespace std;

class Time
{
private:
	double hours;
	double minutes;
	double seconds; // attributes

public: // public interferce
	Time(); // constructor
	void setHours(double); // mutator
	void setMinutes(double);
	void setSeconds(double);
	double timeInHours() const; // accessor
	double timeInMinutes() const;
	double timeInSeconds() const;
};
bool operator<(const Time &, const Time &);

#endif MOONJEONGOOKLAB01BTIME_H

