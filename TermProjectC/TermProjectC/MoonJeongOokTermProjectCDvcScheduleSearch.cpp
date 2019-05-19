// Term Project C, Writing DvcSchedule Search
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
	cout << "Term Project C, Writing DvcSchedule Search\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing DvcSchedule Search\" program" << endl << endl;

	clock_t startTime = clock(); //start the timer
															 //opening the file
	ifstream fin;
	fin.open("dvc-schedule.txt");

	//checking if the file got opened successfully
	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

	//creating a map declaration
	//<Term, map<sections, course>> classData
	map<string, map<string, string>> classData;

	//<Term, map<sections, course>> duplicateData
	map<string, map<string, string>> duplicateData;

	//<Year, map<term, map<section, course>>> searchData;
	map<string, map<string, map<string, string>>> searchData;

	//initiate lineCounter
	unsigned int lineCounter = 0;

	cout << "\nLoading the DVC-schedule" << endl << endl;
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
		string year(term.begin() + term.find(' ') + 1, term.end());
		string newterm(term.begin(), term.begin() + term.find(' '));

		//skipping duplicate
		if (duplicateData.find(term) != duplicateData.end())
		{
			if (duplicateData[term].find(section) != duplicateData[term].end())
			{
				continue;
			}
		}

		searchData[year][newterm][section] = course;
		// saving duplicate data into duplicateData;
		duplicateData[term][section] = course;

	}
	fin.close();
	//stop the timer
	double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

	// initiate pointer 
	map<string, map<string, map<string, string>>>::iterator listPtr;
	
	while (true)
	{
		cout << "\n\nPlease enter a course name that you wish to find in the DVC-schedule" << endl;
		cout << "(Press x or X to quit)" << endl;
		string answer;
		getline(cin, answer);

		if (answer == "x" || answer == "X")
			break;
		else
		{
			// traveling year
			for (listPtr = searchData.begin(); listPtr != searchData.end(); listPtr++)
			{

				if ((*listPtr).first == "2014")
				{
					// traveling each list in the list of classData from beginning to the end
					// traveling term spring, summer, fall
					for (map<string, map<string, string>>::reverse_iterator listPtr2 = (*listPtr).second.rbegin(); listPtr2 != (*listPtr).second.rend(); listPtr2++)
					{
						for (map<string, string>::iterator listPtr3 = (*listPtr2).second.begin(); listPtr3 != (*listPtr2).second.end(); listPtr3++)
						//adding each section's count to count
						if (answer == (*listPtr3).second)
						{
							cout << answer << " was last offered in " << (*listPtr).first << " " << (*listPtr2).first <<endl;
							break;
						}
					}
				}
				else
				{
					////traveling each list in the list of classData from beginning to the end
					//for (map<string, string>::iterator listPtrInsideList = (*listPtr).second.begin(); listPtrInsideList != (*listPtr).second.end(); listPtrInsideList++)
					//{
					//	//adding each section's count to count
					//	if (answer == (*listPtrInsideList).second)
					//	{
					//		cout << answer << "  has not been offered since the year " << (*listPtr).first << endl;
					//		break;
					//	}
					//}
				}
					
			}
		}
	}
	
	cout << "\nTime spent: " << elapsedSeconds << endl;

	cin.get();

}
