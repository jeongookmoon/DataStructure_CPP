#ifndef MOONJEONGOOKLAB02ATIME_H
#define MOONJEONGOOKLAB02ATIME_H

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
	void setHours(const double&); // mutator
	void setMinutes(const double&);
	void setSeconds(const double&);
	double timeInHours() const; // accessor
	double timeInMinutes() const;
	double timeInSeconds() const;
};
bool operator<(const Time&, const Time&); // prototype
bool operator==(const Time&, const Time&);

#endif //MOONJEONGOOKLAB02ATIME_H
