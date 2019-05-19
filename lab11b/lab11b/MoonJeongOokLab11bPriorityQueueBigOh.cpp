// Lab 11b, Performing A Simple Timing Study
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <cassert>

#include "MoonJeongOokLab11aPriorityQueue.h"

using namespace std;

int main()
{
	cout << "Lab 11b, Performing A Simple Timing Study\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing And Testing A Priority Queue Template\" program" << endl << endl;
		
	unsigned int n = 50000;	// 30,000; 60,000; 120,000; 240,000; + 3000. 
	string bigOh = "O(n log n)";
	PriorityQueue<int> originalA(1000000);
	int elapsedTimeTicksNorm = 0;
	double expectedTimeTicks = 0;
	clock_t startTime, endTime;
	cout << "Enqueue," << endl;

	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		
		originalA.makeEmpty();
		
		for (unsigned int i = 0; i < n; i++)
		{
			originalA.Enqueue(i);
		}
		const int REPS = n + 123;
		startTime = clock();
		for (int reps = 0; reps < REPS; reps++)
		{
			originalA.Enqueue(reps);
		}
		endTime = clock();
					
		
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

	n = 50000;
	cout << "\nDequeue," << endl;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		originalA.makeEmpty();

		for (unsigned int i = 0; i < n; i++)
		{
			originalA.Enqueue(i);
		}
		const int REPS = n + 1;
		startTime = clock();
		for (unsigned int reps = 0; reps < REPS; reps++)
		{
			originalA.Dequeue();
		}
		endTime = clock();
		
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