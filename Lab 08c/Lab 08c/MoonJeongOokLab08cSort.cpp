// Lab 8c, Perform A Timing Study On The STL Array Sort Function
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Lab 8c, Perform A Timing Study On The STL Array Sort Function\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Perform A Timing Study On The STL Array Sort Function\" program" << endl << endl;

	


	int n = 4000;
	string bigOh = "O(n)";

	

	int elapsedTimeTicksNorm = 0;
	double expectedTimeTicks = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		double * originalA = new double[n];
		vector<int> vectorA(originalA, originalA + n);

		clock_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			double min = 0;
			srand(time(NULL));
			double max = rand();
			srand(1);
			double input = min + rand() * (max - min);
			
			originalA[i] = input;
		}

		sort(originalA, originalA + n);
		

		for (int i = 1; i < n; i++)
			assert(originalA[i - 1] <= originalA[i]);

		delete[] originalA;

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
