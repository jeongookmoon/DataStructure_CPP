// Term Project A, Writing the Final Version of DvcSchedule
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
	cout << "Term Project A, Writing the Final Version of DvcSchedule\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing the Final Version of DvcSchedule\" program" << endl << endl;

	clock_t startTime = clock(); //start the timer
	//opening the file
	ifstream fin;
	fin.open("dvc-schedule.txt");

	//checking if the file got opened successfully
	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

	//creating two map declarations

	//<subjectCode, map<course, count> classData
	map<string, map<string, int>> classData;

	//<Term, map<sections, course>> duplicateData
	map<string, map<string, string>> duplicateData;

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
		
		string subjectCode(course.begin(), course.begin() + course.find('-')); // end of parsing the line

		//putting subjectCode and course and increasing section count by 1
		classData[subjectCode][course]++;
		
		//finding duplicate
		if (duplicateData.find(term) != duplicateData.end())
		{
			if (duplicateData[term].find(section) != duplicateData[term].end())
			{
				duplicateCount++;
				continue;
			}
		}
		// saving duplicate data into duplicateData;
		duplicateData[term][section] = course;
		
	}
	fin.close();
	//stop the timer
	double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
	
	cout << "\n\nDuplicate found:" << duplicateCount << endl << endl;
	
	// initiate pointer 
	map<string, map<string, int>>::iterator listPtr;

	//<subjectCode, map<course, count> classData
	//travling each list in classData from beginning to the end
	for (listPtr = classData.begin(); listPtr != classData.end(); listPtr++)
	{
		//console out subjectCode
		cout << (*listPtr).first << ", ";
		//initiate count for how many sections there are for each subjectCode
		int count = 0;
		//traveling each list in the list of classData from beginning to the end
		for (map<string, int>::iterator listPtrInsideList = (*listPtr).second.begin(); listPtrInsideList != (*listPtr).second.end(); listPtrInsideList++)
		{	
			//adding each section's count to count
			count = (*listPtrInsideList).second + count;
		}
		//console out the total number of sections for each subjectCode
		cout << count << " sections" << endl;
	}
	
	cout << "\nTime spent: " << elapsedSeconds << endl;
	
	cin.get();

}
