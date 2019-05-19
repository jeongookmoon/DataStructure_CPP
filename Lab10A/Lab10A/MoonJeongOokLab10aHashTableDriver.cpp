// Lab 10a, Writing And Testing The HashTable Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MoonJeongOokLab10aHashTable.h"
using namespace std;

struct TermSection
{
	string term;
	string section;
	bool operator==(const TermSection &rv_info) const;
};
bool TermSection::operator==(const TermSection &rv_info) const
{
	if (term == rv_info.term)
	{
		if (section == rv_info.section)
			return true;
	}
	else
		return false;	
}

int TSHash(const TermSection &rv_info)
{
	
	int ts = rv_info.term.size();
	int ss = rv_info.section.size();
	int hashkey = 0;
	for (int i = 0; i < ts; i++)
		hashkey = hashkey * 3 + rv_info.term[i];
	for (int i = 0; i < ss; i++)
		hashkey = hashkey * 7 + rv_info.section[i];
	return hashkey;
}

int main()
{
	cout << "Lab 10a, Writing And Testing The HashTable Class Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing And Testing The HashTable Class Template\" program" << endl << endl;
	
	TermSection dvcinfo;
	const int cap = 400;

	cout << "******************************************************************************" << endl;
	cout << "Creating instance of HashTable<TermSection, int, cap> dvcinfoTable(TSHash)\ncap = 400...." << endl;
	HashTable<int, TermSection, cap> dvcinfoTable(TSHash);
	cout << "\nTest on empty dvcinfoTable .............. " << endl;
	
	cout << "\nExpected capacity of empty dvcinfoTable is 320 (.8 * 400)" << endl;
	cout << "(Actual) Capacity of dvcinfoTable : " << dvcinfoTable.Capacity() << endl;
	cout << "Expected size of empty dvcinfoTable is 0" << endl;
	cout << "(Actual) Size of dvcinfoTable : " << dvcinfoTable.Size() << endl;
	cout << "\nContainsKey test on empty dvcinfoTable ... " << endl;
	cout << "Key is dvcinfo (section 1111, term Spring) ..." << endl;
	cout << "Expected value for dvcinforTable.ContainsKey(dvcinfo) is false" << endl;
	cout << boolalpha << "(Actual) value for dvcinforTable.ContainsKey(dvcinfo) is " << dvcinfoTable.ContainsKey(dvcinfo) << endl;
	cout << "\nDeleteKey test on empty dvcinfoTable ... " << endl;
	cout << "Key is dvcinfo (section 1111, term Spring) ..." << endl;
	cout << "Expected value for dvcinforTable.DeleteKey(dvcinfo) is false" << endl;
	cout << "(Actual) value for dvcinforTable.DeleteKey(dvcinfo) is " << dvcinfoTable.DeleteKey(dvcinfo) << endl;
	cout << "******************************************************************************" << endl;

	cout << "\nAsssigning 5 course information to dvcinfoTable... \nby dvcinfoTable[dvcinfo] = courseCredits " << endl << endl;
	cout << "section : 3123, term = Srping, courseCredits = 1";
	dvcinfo.section = "3123";
	dvcinfo.term = "Spring";
	int courseCredits = 1;
	dvcinfoTable[dvcinfo] = courseCredits;
	cout << ", Hashkey is " << TSHash(dvcinfo) << endl;

	cout << "section : 3947, term = Fall, courseCredits = 2";
	dvcinfo.section = "3947";
	dvcinfo.term = "Fall";
	courseCredits = 2;
	dvcinfoTable[dvcinfo] = courseCredits;
	cout << ", Hashkey is " << TSHash(dvcinfo) << endl;

	cout << "section : 3654, term = Summer, courseCredits = 3";
	dvcinfo.section = "3654";
	dvcinfo.term = "Summer";
	courseCredits = 3;
	dvcinfoTable[dvcinfo] = courseCredits;
	cout << ", Hashkey is " << TSHash(dvcinfo) << endl;

	cout << "section : 3123, term = Fall, courseCredits = 4";
	dvcinfo.section = "3123";
	dvcinfo.term = "Fall";
	courseCredits = 4;
	dvcinfoTable[dvcinfo] = courseCredits;
	cout << ", Hashkey is " << TSHash(dvcinfo) << endl;

	cout << "section : 3985, term = Srping, courseCredits = 5";
	dvcinfo.section = "3985";
	dvcinfo.term = "Spring";
	courseCredits = 5;
	dvcinfoTable[dvcinfo] = courseCredits;
	cout << ", Hashkey is " << TSHash(dvcinfo) << endl << endl;


	cout << "Expected capacity of empty dvcinfoTable is 320 (.8 * 400)" << endl;
	cout << "(Actual) Capacity of dvcinfoTable : " << dvcinfoTable.Capacity() << endl;
	cout << "Expected size of empty dvcinfoTable is 5" << endl;
	cout << "(Actual) Size of dvcinfoTable : " << dvcinfoTable.Size() << endl;

	cout << "\nShowing dvcinfoTable keys by vector<TermSection> keys = dvcinfoTable.Keys()" << endl;
	vector<TermSection> keys = dvcinfoTable.Keys();
	for (TermSection n : keys)
	{
		cout << n.term << ", " << n.section << endl;
	}

	cout << "\nShowing courseCredits of keys on dvcinfoTable" << endl;
	cout << "section : 3123, term = Spring, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3947, term = Fall, courseCredits = ";
	dvcinfo.section = "3947";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3654, term = Summer, courseCredits = ";
	dvcinfo.section = "3654";
	dvcinfo.term = "Summer";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3123, term = Fall, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3985, term = Spring, courseCredits = ";
	dvcinfo.section = "3985";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "******************************************************************************" << endl;
	cout << "\nChanging key (term = Spring, section = 3985)'s courseCredits to 3\nby dvcinfoTable[dvcinfo] = 3" << endl;
	dvcinfo.section = "3985";
	dvcinfo.term = "Spring";
	courseCredits = 3;
	dvcinfoTable[dvcinfo] = courseCredits;

	cout << "Expected capacity of empty dvcinfoTable is still 320 (.8 * 400)" << endl;
	cout << "(Actual) Capacity of dvcinfoTable : " << dvcinfoTable.Capacity() << endl;
	cout << "Expected size of empty dvcinfoTable is still 5" << endl;
	cout << "(Actual) Size of dvcinfoTable : " << dvcinfoTable.Size() << endl;
	
	cout << "\nShowing courseCredits of keys on dvcinfoTable" << endl;
	cout << "section : 3123, term = Spring, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3947, term = Fall, courseCredits = ";
	dvcinfo.section = "3947";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3654, term = Summer, courseCredits = ";
	dvcinfo.section = "3654";
	dvcinfo.term = "Summer";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3123, term = Fall, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3985, term = Spring, courseCredits = ";
	dvcinfo.section = "3985";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "******************************************************************************" << endl;
	cout << "\nDeleteing key (term = Spring, section = 3985)\nby dvcinfoTable.DeleteKey(dvcinfo)" << endl;
	dvcinfoTable.DeleteKey(dvcinfo);
	cout << "Expected capacity of empty dvcinfoTable is still 320 (.8 * 400)" << endl;
	cout << "(Actual) Capacity of dvcinfoTable : " << dvcinfoTable.Capacity() << endl;
	cout << "Expected size of empty dvcinfoTable is 4" << endl;
	cout << "(Actual) Size of dvcinfoTable : " << dvcinfoTable.Size() << endl;

	cout << "\nShowing courseCredits of keys on dvcinfoTable" << endl;
	cout << "section : 3123, term = Spring, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3947, term = Fall, courseCredits = ";
	dvcinfo.section = "3947";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3654, term = Summer, courseCredits = ";
	dvcinfo.section = "3654";
	dvcinfo.term = "Summer";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3123, term = Fall, courseCredits = ";
	dvcinfo.section = "3123";
	dvcinfo.term = "Fall";
	cout << dvcinfoTable[dvcinfo] << endl;

	cout << "section : 3985, term = Spring, courseCredits = ";
	dvcinfo.section = "3985";
	dvcinfo.term = "Spring";
	cout << dvcinfoTable[dvcinfo] << endl;
	cout << "This courseCredit shows a dummy value since this key got deleted" << endl;
	cout << "******************************************************************************" << endl;

	cout << "\nClear test on dvcinfoTable by dvcinfoTable.Clear()" << endl;
	dvcinfoTable.Clear();

	cout << "Expected capacity of empty dvcinfoTable is still 320 (.8 * 400)" << endl;
	cout << "(Actual) Capacity of dvcinfoTable : " << dvcinfoTable.Capacity() << endl;
	cout << "Expected size of empty dvcinfoTable is 0" << endl;
	cout << "(Actual) Size of dvcinfoTable : " << dvcinfoTable.Size() << endl;

	cin.get();
}