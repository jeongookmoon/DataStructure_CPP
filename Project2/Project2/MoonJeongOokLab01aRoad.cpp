#include "MoonJeongOokLab01aRoad.h"

Road::Road()
{
	length = 0.0;
	width = 0.0;
} // setting initial values for each member

void Road::setWidth(double a)
{
	if (a < 0)
		width = 0;
	else
		width = a;
} // setting width from input

void Road::setLength(double a)
{
	if (a < 0)
		length = 0;
	else
		length = a;
} // setting length from input

double Road::getWidth() const  /// accessor
{
	return width;
} // showing width

double Road::getLength() const  /// accessor
{
	return length;
} // showing length

double Road::asphalt(double v)
{
	return v * width * length * 5280 / 12;
} // accepting parameter in inch and calculating net asphalt needed in cubic feet.
