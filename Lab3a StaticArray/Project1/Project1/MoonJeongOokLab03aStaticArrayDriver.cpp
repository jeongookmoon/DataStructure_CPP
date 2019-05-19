// Lab 3a, Write A Static Array Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MoonJeongOokLab03aStaticArray.h"
using namespace std;

template <class T, unsigned int M>
ostream & operator<<(ostream & os, const StaticArray<T, M> object)
{
	os << "(";
	int i = 0, s = object.Size();
	vector<unsigned int> inUse = object.Keys();
	if (s != inUse.size())
		throw ("Error in operator<<");
	while (i < s)
	{
		os << "{" << inUse[i] << ":" <<
			object[inUse[i]] << "}";
		i++;
		if (i < s)
			os << ", ";
	}
	os << ")";
	return os;
}


int main()
{
	StaticArray<double, 100> A1;
	StaticArray<string, 100> A2;

	cout << "Showing default values for each object:" << endl;
	cout << "A1: " << A1 << endl;
	cout << "A2: " << A2 << endl;

  A1[1] = 34;
  A1[7] = 31;
  A2[4] = "asjkadsjdsa";

	cout << endl << "After putting random values into each object:" << endl;
	cout << "(float numbers for A1, string for A2)" << endl;
	cout << "A1: " << A1 << endl << endl;
	cout << "A2: " << A2 << endl << endl;




	cout << "\n\nShowing size test:" << endl;
	cout << "A1.Size(): " << A1.Size() << endl;
	cout << "A2.Size(): " << A2.Size() << endl;


	cout << "Showing capacity test:" << endl;
	cout << "A1.Capacity (100): " << A1.Capacity() << endl;
	cout << "A2.Capacity (100): " << A2.Capacity() << endl;


	cout << "ContainsKey test:" << endl;
	cout.setf(ios_base::boolalpha);
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "{" << A2.ContainsKey(i) << "}";
		if (i < 9)
			cout << ", ";
	}
	cout << endl << endl;
	cout.unsetf(ios_base::boolalpha);

	cout << "Delete Key test: " << endl;
	for (unsigned int i = 0; i < 10; ++i)
	{
		if (A2.ContainsKey(i))
		{
			cout << "Deleting " << i << endl;
			A2.DeleteKey(i);
			break;
		}
	}
	cout << "A2 (first 10): ";
	cout.setf(ios_base::boolalpha);
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "{" << A2.ContainsKey(i) << "}";
		if (i < 9)
			cout << ", ";
	}
	cout << endl << endl;
	cout.unsetf(ios_base::boolalpha);

	cout << "Keys test:" << endl;
	vector<unsigned int> keys;
	keys = A2.Keys();
	cout << "A2.Keys: ";
	for (unsigned int i = 0; i<keys.size(); ++i)
	{
		cout << keys[i];
		if (i < keys.size() - 1) cout << ",";
	}
	cout << endl << endl;

	cout << "Clear test: " << endl;
	A2.Clear();
	keys = A2.Keys();
	cout << "A2.Keys: ";
	for (unsigned int i = 0; i<keys.size(); ++i)
	{
		cout << keys[i];
		if (i < keys.size() - 1) cout << ",";
	}
	cout << endl << endl;

	cout << "Please enter" << endl;
	cin.get();
}
