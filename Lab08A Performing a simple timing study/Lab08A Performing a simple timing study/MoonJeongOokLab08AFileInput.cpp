// Lab 8a, Performing a Simple Timing Study
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express


#include <iostream>
#include <string> 
#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <fstream> // to open file
using namespace std;




int main()
{
	cout << "Lab 8a, Performing a Simple Timing Study\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Performing a Simple Timing Study\" program" << endl << endl;

	int n = 5000; 
	string bigOh = "O(n)"; 

	int elapsedTimeTicksNorm = 0;
	double expectedTimeTicks = 0;

	
	
	
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		ifstream fin;
		fin.open("dvc-schedule.txt");

		if (!fin.good())
			throw(exception(" Error : Can't open the file! "));

		unsigned int lineCounter = 0;

		clock_t startTime = clock();

		for (lineCounter; lineCounter < n; lineCounter++)
		{
			

			string line;
			getline(fin, line);

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
		}

		fin.close();


		clock_t endTime = clock();

		long elapsedTimeTicks = (long)(endTime - startTime);
		double factor = pow(2.0, cycle);
		if (cycle == 0)
			elapsedTimeTicksNorm = elapsedTimeTicks;
		else if (bigOh == "O(1)")
			expectedTimeTicks = elapsedTimeTicksNorm;
		else if (bigOh == "O(log n)")
			expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
		else if (bigOh == "O(n)")
			expectedTimeTicks = factor * elapsedTimeTicksNorm;
		else if (bigOh == "O(n log n)")
			expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
		else if (bigOh == "O(n squared)")
			expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
		// reporting block
		cout << elapsedTimeTicks;;
		if (cycle == 0) cout << " (expected " << bigOh << ')';
		else cout << " (expected " << expectedTimeTicks << ')';
		cout << " for n=" << n << endl;
	}
	
	cin.get();
}

	
