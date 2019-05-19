// Lab 3b, Write A Static Array Application
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include "MoonJeongOokLab03bStaticArray.h"
using namespace std;

int main()
{
    StaticArray<double, 100> A1;
	cout << "Input an index and a value [Q to quit]: ";
	while (true)
	{
		string mystr;
		int index, value;
		getline(cin, mystr);
		stringstream(mystr) >> index >> value;
		if ( mystr == "q" || mystr == "Q") 
		{			
			break;
			
		}
		
		else
		{
			A1[index] = value;
			cout << "Input an index and a value [Q to quit]: ";
		}
	}
	cout << "I stored these many values: ";
	cout << A1.Size() << endl;
	cout << "The Values are: " << endl;
	cout << A1 << endl;
	cout << "Input an index for me to look up[ Q to quit ]: ";
	while (true)
	{
		string mystr2;
		int lookup;
		getline(cin, mystr2);
		stringstream(mystr2) >> lookup;
		if (mystr2 == "Q" || mystr2 == "q")
		{
			cout << "Bye" << endl;
			break;
		}
		else
		{
			if (A1.ContainsKey(lookup) == true)
			{
				cout << "Found it -- the value stored at " << lookup << " is " << A1[lookup] << endl;
				cout << "Input an index for me to look up[ Q to quit ]: ";
			}
			else
			{
				cout << "I didn't find it" << endl;
				cout << "Input an index for me to look up[ Q to quit ]: ";
			}

		}
	}
	cin.get();
}