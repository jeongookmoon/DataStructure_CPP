// Lab 8b, Perform A Timing Study On Nested For-Loop Sorting
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	cout << "Lab 8b, Performing a Timing Study on Nested For-loop sorting\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Performing a Timing study on Nested For-loop sorting\" program" << endl << endl;

	


	int n = 3000;
	string bigOh = "O(n squared)";



	int elapsedTimeTicksNorm = 0;
	double expectedTimeTicks = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		double * originalA = new double[n];
		
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

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (originalA[j] < originalA[i])
					swap(originalA[i], originalA[j]);


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

