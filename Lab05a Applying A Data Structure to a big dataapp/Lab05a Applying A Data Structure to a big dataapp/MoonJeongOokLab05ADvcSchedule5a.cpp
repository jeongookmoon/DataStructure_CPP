// Lab 5a, Applying A Data Structure To A Big Data Application
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream> // for cout
#include <array> // for array
#include <string> // for string
#include <fstream> // to open file
using namespace std;

#include "MoonJeongOokLab04aDynamicArray.h"

#include <cstring>
#include <ctime>

struct Data
{
	string subject;
	int count;
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
	cout << "Lab 5A, Applying A Data Structure To A Big Data Application\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

	DynamicArray<Data> classData;
	DynamicArray<ForDuplicate> duplicateData;

	int i, k;
	int size;
	int duplicateCount = 0;
	unsigned int lineCounter = 0;

	const char* const tab = "\t";

	clock_t startTime = clock(); //start the timer

	ifstream fin;
	fin.open("dvc-schedule.txt");

	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

		while (lineCounter != 5000)
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
				
				int maxsize = classData.Size();

				for (k = 0; k < maxsize; k++)
				{
					if (classData[k].subject == subjectCode) break; // when the same subject code is found
				}

				if (k == maxsize) // When i reaches classData's maximum size, creating newobject of struct and assigning subjectCode and count, appending it to the array as well.
				{
					Data newObject;
					newObject.subject = subjectCode;
					newObject.count = 1;
					classData[classData.Size()] = newObject;
				}
				else
				{

					classData[k].count++;
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

		cout << endl;
		for (i = 0; i < classData.Size(); i++)
		{
			cout << classData[i].subject << ", " << classData[i].count
				<< " sections" << endl;
		}

		cout << "\nTime spent: " << elapsedSeconds << endl;
		cin.get();
}
