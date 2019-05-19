// Lab 13a, Write A Sortable Array Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MoonJeongOokLab13aSortableStaticArray.h"

using namespace std;

template <class T, unsigned int CAPACITY>
ostream & operator<<(ostream & show, const SortableStaticArray<T, CAPACITY> rv_Array)
{
	int max = rv_Array.Size();
	vector<unsigned int> inUse = rv_Array.Keys();

	if ( max != inUse.size())
		throw ("Error in operator<<");

	for (int i = 0; i < max; i++)
	{
		show << "[index : " << inUse[i] << ", value : " <<
			rv_Array[inUse[i]] << "]";
		
		if (i + 1 < max)
			show << ", ";

		if ((i+1) % 2 == 0)
			show << "\n";
	}
	return show;
}


int main()
{
	cout << "Lab 13a, Writing A Sortable Array Class Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing A Sortable Array Class Template\" program" << endl << endl;

	cout << "Creating a sortable static array originalA<double, 100>..." << endl;

	SortableStaticArray<double, 100> originalA;

	cout << "----------------------------------------------------------" << endl;

	cout << "\nShowing what's inside originalA:" << endl;
	cout << "originalA: " << originalA << endl;

	cout << "\nSize of originalA is " << originalA.Size() << endl;
	cout << "Capacity of originalA is " << originalA.Capacity() << endl;

	cout << "----------------------------------------------------------" << endl;
		
	cout << "\nPutting values into originalA..." << endl;
	
	for (int i = 0; i < 100; i++)
	{
		cout << "Please enter a float number (press x or X to quit)" << endl;
		string value;
		cin >> value;
		cin.ignore();
		if (value == "x" || value == "X")
			break;
		originalA[i] = atof(value.c_str());
	}
	
	cout << "\nSize of originalA is " << originalA.Size() << endl;
	cout << "Capacity of originalA is " << originalA.Capacity() << endl;

	cout << "\nShowing what's inside originalA (unsorted)" << endl;
	cout << originalA << endl;

	cout << "----------------------------------------------------------" << endl;

	cout << "\nNow sorting originalA in low to high value order...." << endl;
	originalA.Sort();

	cout << "\nSize of sorted originalA is " << originalA.Size() << endl;

	cout << "\nShowing what's inside originalA (sorted)" << endl;
	cout << originalA << endl << endl;
	
	while (true)
	{
		int startIndex = 0;
		int endIndex = originalA.Size();
		string answer;
		cout << "Please enter a float number that you wish to find...(x or X to quit)" << endl;
		cin >> answer;
		cin.ignore();
		if (answer == "x" || answer == "X")
			break;
		while (answer != "x" || answer != "X")
		{
			double value;
			value = atof(answer.c_str());

			int midIndex = (startIndex + endIndex - 1) / 2;

			// got lucky -- matches middle element
			if (value == originalA[midIndex])
			{
				cout << "Found at index " << midIndex << endl;
				break;
			}
			// 1-element array
			else if (startIndex == (endIndex - 1))
			{
				cout << "There's no match" << endl; //only element in array did not match
				break;
			}
			// look between startIndex and endIndex-1
			else if (value < originalA[midIndex])
			{
				if (startIndex == midIndex)
				{
					cout << "There's no match" << endl; // but that range is empty, no match
					break;
				}
				// look in startIndex to midIndex-1	
				else
				{
					endIndex = midIndex;
					continue;
				}
			}
			else // look between midIndex+1 and endIndex-1
			{
				if (midIndex == (endIndex - 1))
				{
					cout << "There's no match" << endl; // but that range is empty, no match
					break;
				}
				else
				{
					startIndex = midIndex + 1; //look in midIndex-1 to endIndex
					continue;
				}
			}
		}
	}
	

	/*outputs the size of the SortableStaticArray object,
	outputs the number of values actually entered by the user(which should match the above),
	outputs the unsorted list, one a single line, comma - separated, for the #of entered values,
	sorts the data entries made by the user, lo - to - hi for the #of entered values, and outputs them; AND.
	implements binary search in a user - controlled loop, allowing multiple searches until the user elects to stop*/
	
	cout << "\nContainsKey test...(Showing fisrt 10 indexes only)" << endl;
	cout.setf(ios_base::boolalpha);
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "[Index : " << i << ", " << originalA.ContainsKey(i) << "]";
		if (i < 9)
			cout << ", ";
		if ((i + 1) % 2 == 0)
			cout << endl;
	}
	cout << endl << endl;
	cout.unsetf(ios_base::boolalpha);

	cout << "Delete Key test...(Deleting first 2 indexes only)" << endl;
	for (unsigned int i = 0; i < 2; ++i)
	{
		if (originalA.ContainsKey(i) == true)
		{
			originalA.DeleteKey(i);
		}
	}
		
	cout << "\nContainsKey test...(Showing fisrt 10 indexes only)" << endl;
	cout.setf(ios_base::boolalpha);
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "[Index : " << i << ", " << originalA.ContainsKey(i) << "]";
		if (i < 9)
			cout << ", ";
		if ((i + 1) % 2 == 0)
			cout << endl;
	}
	cout.unsetf(ios_base::boolalpha);

	cout << "\nKeys test..." << endl;
	vector<unsigned int> keys;
	keys = originalA.Keys();

	cout << "originalA.Keys are ";
	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		cout << keys[i];
		if (i < keys.size() - 1) 
			cout << ",";
	}
	cout << endl;
	cout << "\nClear test by originalA.Clear()" << endl;
	originalA.Clear();

	cout << "Showing orignalA.Keys()..." << endl;
	keys = originalA.Keys();
	for (unsigned int i = 0; i<keys.size(); ++i)
	{
		cout << keys[i];
		if (i < keys.size() - 1)
			cout << ",";
	}

	cin.get();
}
