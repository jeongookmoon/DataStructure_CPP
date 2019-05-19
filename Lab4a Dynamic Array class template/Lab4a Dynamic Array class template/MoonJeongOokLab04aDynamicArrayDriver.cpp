// Lab 4a, Write A Dynamic Array Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <array>
#include <string>

#include "MoonJeongOokLab04aDynamicArray.h"
using namespace std;


int main()
{
	cout << "MoonJeongOok4aDynamicArrayDriver.cpp\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
	cout << "The \"Dynamic Array Class Template\" program" << endl << endl;

	DynamicArray<string> s1;

	cout << "Showing default values in s1: " << endl;
	cout << "s1: \n" << s1;
	cout << "Putting some values into s1..... " << endl;

	s1[23] = "Atoz";
	s1[72] = "cmx";
	s1[3] = "slq";
	s1[17] = "!akq";
	s1[6] = "szaq";
	s1[9] = "czc";

	cout << "\nAfter assigning some values into s1, s1: " << endl;
	cout << s1 << endl ;

	cout << "Creating s2 with s1's values in it....." << endl;
	const DynamicArray<string> s2(s1);
	cout << "s2: \n" << s2 << endl;


	DynamicArray<string> s3;
	cout << "Creating new s3.....\ns3: " << s3 << endl;
	cout << "Making s3 = s1" << endl;
	s3 = s1;
	cout << "s3: \n" << s3 << endl << endl;

	cout << "[] const test.... " << endl;
	cout << "Showing first 10 values of s2 : \n";
	bool needComma;
	needComma = false;
	for (unsigned int i = 0; i < 10; ++i)
	{
		if (s2.ContainsKey(i))
		{
			if (needComma)
				cout << ", ";
			needComma = true;
			cout << "<< " << i << " : ";
			cout << s2[i] << ">>";
		}
	}


	cout << "\nSize() test: " << endl;
	cout << "s1.Size(): " << s1.Size() << endl;
	cout << "s2.Size(): " << s2.Size() << endl;
	cout << "s3.Size(): " << s3.Size() << endl << endl;

	cout << "Capacity() test: " << endl;
	cout << "s1.Capacity(): " << s1.Capacity() << endl;
	cout << "s2.Capacity(): " << s2.Capacity() << endl;
	cout << "s3.Capacity(): " << s3.Capacity() << endl << endl;

	cout << "ContainsKey test: " << endl;
	cout << "Showing first 10 values of s3 : \n";

	needComma = false;
	for (unsigned int i = 0; i < 10; ++i)
	{
		if (s3.ContainsKey(i))
		{
			if (needComma)
				cout << ", ";
			needComma = true;
			cout << "<< " << i << " : ";
			cout << s3[i] << ">>";
		}
	}

	cout << "\nDeleteKey test: " << endl;
	for (unsigned int i = 0; i < s3.Size(); ++i)
	{
		if (s3.ContainsKey(i))
		{
			s3.DeleteKey(i);
			cout << "Deleted key : " << i << endl;
			break;
		}
	}
	cout << "s3 (first 10 after delete): \n";
	needComma = false;
	for (unsigned int i = 0; i < 10; ++i)
	{
		if (s3.ContainsKey(i))
		{
			if (needComma)
				cout << ", ";
			needComma = true;
			cout << "<< " << i << " : ";
			cout << s3[i] << ">>";
		}
	}

	cout << "\nKeys test: " << endl;
	vector<unsigned int> indices;
	indices = s3.Keys();
	cout << "s3 keys: ";
	needComma = false;
	for (unsigned int i = 0; i < indices.size(); ++i)
	{
		if (needComma) cout << ", ";
		needComma = true;
		cout << indices[i];
	}
	cout << endl << endl;

	cout << "Clear test: " << endl;
	s3.Clear();
	cout << "s3 : \n" << s3 << endl;
	cout << "Please enter" << endl;
	cin.get();
}
