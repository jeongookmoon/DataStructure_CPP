// Lab 9a, Writing And Testing The AssociativeArray Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include "MoonJeongOokLab09aAssociativeArray.h"

#include <fstream>
#include <cstring>
#include <string>
#include <cassert>

using namespace std;


struct TermSection
{
	string term;
	string section;
};

bool operator==(const TermSection& x, const TermSection& y)
{
	if (x.term != y.term)
		return false;
	if (x.section != y.section)
		return false;
	return true;
}

template <class Key, class Val>
ostream &operator<<(ostream& show, const Array<Key, Val> receive_array)
{
	vector<Key> inside = receive_array.Keys();
	for (unsigned int i = 0; i < inside.size(); i++)
	{
		show << "Key : " << inside[i] << ", " << "Value : " << receive_array[inside[i]];
		if (i < inside.size() - 1)
			show << "\n";
	}
	return show;
}


int main()
{
	cout << "Lab 9a, Writing And Testing The AssociativeArray Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing And Testing The AssociativeArray Template\" program" << endl << endl;

	unsigned int lineCounter = 0;
	ifstream fin;
	fin.open("dvc-schedule.txt");

	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));
	
	cout << "Creating an instance of an associative array called originalA" << endl;
	Array<TermSection, string> originalA;

	cout << "\nReading each line of dvc-schedule.txt and \nassigning term, section as an index and course as a value" << endl;
	cout << "to an associative array originalA " << endl;
	cout << "\nReading up to 1000 line and in each 100 line there will be .\nand in each 500 line, there will be enter" << endl;
	
	while (fin.good())
	{
		if (lineCounter != 1000)
		{
			lineCounter++; // linecounter starts to increase
			if (lineCounter % 100 == 1) // each 1000 line, there will be . in screen
			{
				cout << "."; cout.flush();
			}
			if (lineCounter % 500 == 0) // each 20000 line, there will be "\n" in screen
				cout << endl;

			string line;
			getline(fin, line);

			size_t current, next = -1;
			current = next + 1;

			next = line.find_first_of("\t\n", current);
			string term = line.substr(current, next - current);

			current = next + 1;
			next = line.find_first_of("\t\n", current);
			string section = line.substr(current, next - current);

			current = next + 1;
			string course;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				course = line.substr(current, next - current);
			}

			current = next + 1;
			string instructor;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				instructor = line.substr(current, next - current);
			}

			current = next + 1;
			string whenWhere;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				whenWhere = line.substr(current, next - current);
			}

			if (course.find('-') == string::npos)
				continue;

			string subjectCode(course.begin(), course.begin() + course.find('-'));

			TermSection ts = { term, section };
			originalA[ts] = course;
		}
		else
		{
			break;
		}
		
	}
	fin.close();

	cout << "\nNow checking if originalA has the same course \nwith dvc-schedule.txt by assert(originalA[term, section] == course)" << endl;
	cout << "\nAgain, reading up to 1000 line and in each 100 line there will be .\nand in each 500 line, there will be enter" << endl;

	fin.open("dvc-schedule.txt");

	lineCounter = 0;

	while (fin.good())
	{
		if (lineCounter != 1000)
		{
			lineCounter++; // linecounter starts to increase
			if (lineCounter % 100 == 1) // each 1000 line, there will be . in screen
			{
				cout << "."; cout.flush();
			}
			if (lineCounter % 500 == 0) // each 20000 line, there will be "\n" in screen
				cout << endl;

			string line;
			getline(fin, line);

			size_t current, next = -1;
			current = next + 1;

			next = line.find_first_of("\t\n", current);
			string term = line.substr(current, next - current);

			current = next + 1;
			next = line.find_first_of("\t\n", current);
			string section = line.substr(current, next - current);

			current = next + 1;
			string course;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				course = line.substr(current, next - current);
			}

			current = next + 1;
			string instructor;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				instructor = line.substr(current, next - current);
			}

			current = next + 1;
			string whenWhere;
			if (current < line.length())
			{
				next = line.find_first_of("\t\n", current);
				whenWhere = line.substr(current, next - current);
			}

			if (course.find('-') == string::npos)
				continue;

			string subjectCode(course.begin(), course.begin() + course.find('-'));

			TermSection ts = { term, section };
			assert(originalA[ts] == course);
		}
		else
		{
			break;
		}

	}
	fin.close();
	
	cout << "\nCreating instance of an associative array<string, double> originalB" << endl;
	Array<string, double> originalB;

	cout << "\nExpected size of originalB is " << 0 << endl;
	cout << "\nExpected capacity of originalB is " << 0 << endl;

	cout << "\nShowing the size of originalB" << endl;
	cout << originalB.Size() << endl;

	cout << "\nShowing the capacity of originalB" << endl;
	cout << originalB.Capacity() << endl;

	cout << "\nTesting ContainsKey on originalB... (on default) " << endl;
	cout << "Testing key is " << "First" << endl;
	cout << "expected value of originalB.ContainsKey(First) is false" << endl;
	cout << "actual value is " << boolalpha << originalB.ContainsKey("First") << endl;

	cout << "\nTesting DeleteKey on originalB... (on default) " << endl;
	cout << "Testing key is " << "First" << endl;
	cout << originalB.DeleteKey("First") << endl;

	cout << "*********************************************************************" << endl;


	string index1, index2, index3;
	index1 = "First";
	index2 = "Second";
	index3 = "Third";
	cout << "\nAssinging index First, Second, Third and\nvalues 1.1, 2.2, 3.3 to originalB" << endl;
	
	originalB[index1] = 1.1;
	originalB[index2] = 2.2;
	originalB[index3] = 3.3;

	cout << "\nExpected values for originalB are ..." << endl;
	cout << 1.1 << endl;
	cout << 2.2 << endl;
	cout << 3.3 << endl;
	
	cout << "\nShowing what's inside originalB... (actual values)" << endl;
	cout << originalB[index1] << endl;
	cout << originalB[index2] << endl;
	cout << originalB[index3] << endl;

	cout << "\nShowing what's inside originalB by using Keys and ostream operator" << endl;
	cout << originalB << endl;

	cout << "\nExpected size of originalB is " << 3 << endl;
	cout << "\nExpected capacity of originalB is " << 3 << endl;

	cout << "\nShowing the size of originalB" << endl;
	cout << originalB.Size() << endl;

	cout << "\nShowing the capacity of originalB" << endl;
	cout << originalB.Capacity() << endl;

	cout << "*********************************************************************" << endl;
		
	cout << "\nCreating instance of an associative array<string, double> copyA" << endl;
	Array<string, double> copyA;

	cout << "\nObject assignment testing by copyA = originalB..." << endl;
	copyA = originalB;

	cout << "\nExpected values of copyA are ... (same as originalB)" << endl;
	cout << originalB[index1] << endl;
	cout << originalB[index2] << endl;
	cout << originalB[index3] << endl;

	cout << "\nShowing what's inside copyA... (actual values)" << endl;
	cout << copyA[index1] << endl;
	cout << copyA[index2] << endl;
	cout << copyA[index3] << endl;
	
	cout << "*********************************************************************" << endl;

	cout << "\nObject copy test by stating Array<string, double> copyB = originalB" << endl;
	Array<string, double> copyB = originalB;

	cout << "\nExpected values of copyB are ... (same as originalB)" << endl;
	cout << originalB[index1] << endl;
	cout << originalB[index2] << endl;
	cout << originalB[index3] << endl;


	cout << "\nShowing what's inside copyB... (actual values)" << endl;
	cout << copyB[index1] << endl;
	cout << copyB[index2] << endl;
	cout << copyB[index3] << endl;

	cout << "*********************************************************************" << endl;

	cout << "\nChainging the value of index Third on copyB... to 4.5" << endl;
	copyB[index3] = 4.5;

	cout << "\nChainging the value of index Second on copyB... to 7.7" << endl;
	copyB[index2] = 7.7;

	cout << "\nExpected values for copyB are ..." << endl;
	cout << 1.1 << endl;
	cout << 7.7 << endl;
	cout << 4.5 << endl;

	cout << "\nShowing what's inside copyB... (actual values)" << endl;
	cout << copyB[index1] << endl;
	cout << copyB[index2] << endl;
	cout << copyB[index3] << endl;

	cout << "*********************************************************************" << endl;

	cout << "\nTesting ContainsKey on copyB...  " << endl;
	cout << "Testing key is " << index1 << endl;
	cout << "expected value of copyB.ContainsKey(index1) is true" << endl;
	cout << "actual value is "<< copyB.ContainsKey(index1) << endl;
	cout << "Testing key is " << "Fourth" << endl;
	cout << "expected value of copyB.ContainsKey(Fourth) is false" << endl;
	cout << "actual value is " << copyB.ContainsKey("Fourth") << endl;


	cout << "*********************************************************************" << endl;


	cout << "\nTesting DeleteKey on copyB...  " << endl;
	cout << "Testing key is " << index1 << endl;
	cout << "expected value of copyB.DeleteKey(First) is true" << endl;
	cout << "actual value is " << copyB.DeleteKey(index1) << endl;

	cout << "\nAfter deleting key First, size should be 2 instead of 3" << endl;
	cout << "Showing actual size of copyB : " << copyB.Size() << endl;
	cout << "\nAfter deleting key First, capacity should remain as 3" << endl;
	cout << "Showing actual capacity of copyB : " << copyB.Capacity() << endl;
	cout << "\nChecking key First got deleted by containsKey..." << endl;
	cout << "expected value of copyB.ContainsKey(First) is false" << endl;
	cout << "actual value is " << copyB.ContainsKey(index1) << endl;


	cout << "*********************************************************************" << endl;


	cout << "\nClear test on copyB" << endl;
	copyB.Clear();
	cout << "\nAfter clearing copyB, size should be 0 instead of 2" << endl;
	cout << "Showing actual size of copyB : " << copyB.Size() << endl;
	cout << "\nAfter deleting key First, capacity should remain as 3" << endl;
	cout << "Showing actual capacity of copyB : " << copyB.Capacity() << endl;
	

	cin.get();
}