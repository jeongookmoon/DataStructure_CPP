// Lab 5b, Using A Data Structure As A Data Member
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "MoonJeongOokLab04aDynamicArray.h"

#include <cstring>
#include <ctime>

struct CourseStruct
{
	string course;
	int count;
};

struct SubjectStruct
{
	string subject;
	DynamicArray<CourseStruct> courses;
};

struct ForDuplicate
{
	string term;
	DynamicArray<string> sections;

	ForDuplicate(string aterm, string section)
	{
		term = aterm;
		sections[0] = section;
	}
	ForDuplicate()
	{
	}
};

int main()
{
	cout << "Lab 5b, Using A Data Structure As A Data Member\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;


	DynamicArray<SubjectStruct> classData;
	DynamicArray<ForDuplicate> duplicateData; 

	int i; // for loop index
	int j; // for loop index
	int k, l;
	int size;
	int duplicateCount = 0; 
	unsigned int lineCounter = 0;

	const char* const tab = "\t";

	clock_t startTime = clock(); //start the timer

	ifstream fin;
	fin.open("dvc-schedule.txt");

	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

	while (fin.good())
	{
		string line;
		getline(fin, line);

		lineCounter++; // linecounter starts to increase
		if (lineCounter % 1000 == 1) // each 1000 line, there will be . in screen
		{
			cout << "."; cout.flush();
		}
		if (lineCounter % 20000 == 0) // each 20000 line, there will be "\n" in screen
			cout << endl;

		if (line[0] == 0)
			continue;

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

		size = duplicateData.Size();
		bool found = false;

		for (i = 0; i < size; i++)
		{
			if (duplicateData[i].term == term) // checking if the term is the same with the term in the i's index in dynamic array duplicateData
			{
				int maxsizeSections = duplicateData[i].sections.Size();
				for (int j = 0; j < maxsizeSections; j++)
				{
					if (duplicateData[i].sections[j] == section) // when found the same section as well
					{
						duplicateCount++; // duplicatecount goes up;
						found = true; // switch bool found to be true
						break;
					}
				}
				break; // after the for loop inside breaks, breaks the outer for loop for faster speed.
			}
		}


		if (!found) // when the duplicate is not found
		{
			if (i < size)
				duplicateData[i].sections[duplicateData[i].sections.Size()] = section; // if i is not at maximum index, then only write section at last index of the array of the duplicatedata array
			else
				duplicateData[duplicateData.Size()] = ForDuplicate(term, section); // if i is at maximum index, then write both term and section. and append it at the end of the duplicateData array

			size = classData.Size();
			
			for (k = 0; k < size; k++) // checking if the same subjectCode is found, if so break;
			{
				if (subjectCode == classData[k].subject) break;
			}

			if (k == classData.Size()) // if not found so i goes to the last index,
			{
				SubjectStruct subjectObj; //create new subject object
				subjectObj.subject = subjectCode; // setting subjectcode to subject of the new subject object

				CourseStruct courseObj; //create new course object,
				courseObj.course = course; //setting course to course of the new course object
				courseObj.count = 1; //setting course count = 1
				subjectObj.courses[subjectObj.courses.Size()] = courseObj; //appending the created new course object to the last index of the course dynamic array of the subject object.
				classData[classData.Size()] = subjectObj; //appending subject object to the last index of the classdata array.
			}
			else
			{
				for (l = 0; l < classData[k].courses.Size(); l++) // checking if the course is the same
				{
					if (course == classData[k].courses[l].course) break;
				}

				if (l == classData[k].courses.Size()) // if the same course is not found,
				{
					CourseStruct courseObj; //create new course object,
					courseObj.course = course; //setting course to course of the new course object
					courseObj.count = 1; //setting course count = 1
					classData[k].courses[classData[k].courses.Size()] = courseObj; //appending course object to the last index of the classData of the course of the classData array.
				}
				else
				{
					classData[k].courses[l].count++; // count goes up when the same subjectCode and course found.
				}
			}

		}

		
	}
	fin.close();

	cout << "\nDuplicate found:" << duplicateCount << endl;

	for (int i = 0; i < classData.Size(); i++)
		for (int j = i + 1; j < classData.Size(); j++)
			if (classData[j].subject < classData[i].subject)
				swap(classData[j], classData[i]);

	//stop the timer
	double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

	//XLS file output
	ofstream fout; // requires fstream
	fout.open("DvcSchedule.xls");
	if (!fout.good()) throw "I/O error";

	//format
	fout << "course" << "\t\t" << "section\n";

	for (i = 0; i < classData.Size(); i++)
	{
		fout << classData[i].subject << "\t" << classData[i].courses.Size()
			<< "\n";
		for (j = 0; j < classData[i].courses.Size(); j++)
		{
			fout << "\t\t" << classData[i].courses[j].course << "\t"
				<< classData[i].courses[j].count << "\n";
		}
	}
	fout.close();

	cout << endl;
	for (i = 0; i < classData.Size(); i++)
	{
		cout << classData[i].subject << ", " << classData[i].courses.Size()
			<< " course(s)" << endl;
		for (j = 0; j < classData[i].courses.Size(); j++)
		{
			cout << "  " << classData[i].courses[j].course << ", "
				<< classData[i].courses[j].count << " section(s)" << endl;
		}
	}

	cout << "\nTime spent: " << elapsedSeconds << endl;
	cin.get();
}
