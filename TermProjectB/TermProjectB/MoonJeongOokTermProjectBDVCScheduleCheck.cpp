// Term Project B, Writing DvcSchedule Checking program
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

int main()
{
	cout << "Term Project B, Writing DvcSchedule Checking program\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing DvcSchedule Checking program\" program" << endl << endl;

	clock_t startTime = clock(); //start the timer
	//opening the file
	ifstream fin;
	fin.open("dvc-schedule.txt");

	//checking if the file got opened successfully
	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

	//creating map declarations
	//<Term, map<sections, subjectCode>> duplicateData
	map<string, map<string, string>> duplicateData;
	//<Term, map<sections, course>> duplicateData_course
	map<string, map<string, string>> duplicateData_course;
	//<Term, map<sections, course>> conflictData
	map<string, map<string, string>> conflictData;
	
	//initiate lineCounter
	unsigned int lineCounter = 0;

	//initiate duplicateCount
	int duplicateCount = 0;
	
	// starting loop up to 70000 lines
	while (lineCounter != 70000)
	{
		//getting each line
		string line;
		getline(fin, line);

		//parse each line
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
		string subjectCodeNumber(course.begin() + course.find('-') + 1, course.end());

		//finding duplicate
		if (duplicateData.find(term) != duplicateData.end())
		{
			if (duplicateData[term].find(section) != duplicateData[term].end())
			{		
				if (duplicateData[term][section] != subjectCode)
				{
					duplicateCount++;
					conflictData[term][section] = course + ", " + duplicateData_course[term][section];
					continue;
				}
			}
		}

		//<Term, map<sections, subjectCodeNumber>> duplicateData
		duplicateData[term][section] = subjectCode;
		//<Term, map<sections, course>> duplicateData_course
		duplicateData_course[term][section] = course;
		
	}
	fin.close();
	
	//stop the timer
	double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

	cout << "\n\n" << duplicateCount << " pairs of conflictions found" << endl << endl;
	
	// initiate pointer 
	map<string, map<string, string>>::iterator listPtr;
	//travling each list in conflictData from beginning to the end
	for (listPtr = conflictData.begin(); listPtr != conflictData.end(); listPtr++)
	{
		//console out term
		cout << "Term : "<< (*listPtr).first << endl;
		//traveling each list in the list of conflictData from beginning to the end
		for (map<string, string>::iterator listPtrInsideList = (*listPtr).second.begin(); listPtrInsideList != (*listPtr).second.end(); listPtrInsideList++)
		{
			
			cout << "Section : " << (*listPtrInsideList).first << " Course : " << (*listPtrInsideList).second << endl;
		}
	}
	
	cout << "\nTime spent: " << elapsedSeconds << endl;
	
	cin.get();

}
