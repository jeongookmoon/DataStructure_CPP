// Lab 14a, Write A Sortable Array Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <array>
#include <string>

#include "MoonJeongOokLab14aSortableDynamicArray.h"
using namespace std;

template <class T>
ostream & operator<<(ostream & show, const SortableDynamicArray<T>& rv_Array)
{
	vector<unsigned int> key = rv_Array.Keys();
	for (unsigned int i = 0; i < key.size(); ++i)
	{
		show << "[Index : " << key[i] << ", value : " <<
			rv_Array[key[i]] << "]";
		if (i < key.size() - 1)
			show << "\n";
	}
	show << "\n";
	return show;
}

int main()
{
	cout << "Lab 14a, Writing A Sortable Array Class Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing A Sortable Array Class Template\" program" << endl << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "Creating a sortable dynamic array<int> originalA..." << endl;
	SortableDynamicArray<int> originalA;
	cout << "Showing default values in originalA: " << endl;
	cout << "originalA: \n" << originalA;
	cout << "Size of originalA is " << originalA.Size() << endl;
	cout << "Capacity of originalA is " << originalA.Capacity() << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "\nPutting some values into originalA..... " << endl;
	int i = 0;
	while (true)
	{
		cout << "\nPlease enter an integer you wish to put into originalA\n(press x or X to quit)" << endl;
		string value;
		getline(cin, value);
		if (value == "x" || value == "X")
			break;
		cout << "originalA[" << i << "] = " << atoi(value.c_str()) << endl;
		originalA[i] = atoi(value.c_str());
		i++;
	}

	cout << "\nSize of originalA is " << originalA.Size() << endl;
	cout << "Capacity of originalA is " << originalA.Capacity() << endl;

	cout << "\nShowing what's inside originalA (unsorted)" << endl;
	cout << originalA << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "How many first elements do you want to sort?" << endl;
	int answer;
	cin >> answer;
	cout << "\nNow, sorting fisrt " << answer << " elements in originalA..." << endl;
	originalA.Sort(answer);
	cout << "Showing what's inside originalA (sorted)" << endl;
	cout << originalA << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "Now, doing binary search..." << endl;

	while (true)
	{
		cout << "How many first elements do you want to search?\n(press x or X to quit)" << endl;
		string value;
		cin >> value;
		cin.ignore();
		if (value == "x" || value == "X")
			break;
		else
		{
			int answer = atoi(value.c_str());
			cout << "Please enter an integer that you wish to search\n(press x or X to quit)" << endl;
			cin >> value;
			cin.ignore();
			if (value == "x" || value == "X")
				break;
			int number = atoi(value.c_str());
			originalA.BinarySearch(answer, number);
			cout << endl;
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
	cout << endl << endl;
	cout.unsetf(ios_base::boolalpha);

	cout << "Delete Key test...(Deleting first 3 indexes only)" << endl;
	for (unsigned int i = 0; i < 3; ++i)
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
	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		cout << keys[i];
		if (i < keys.size() - 1)
			cout << ",";
	}

	cin.get();
}
