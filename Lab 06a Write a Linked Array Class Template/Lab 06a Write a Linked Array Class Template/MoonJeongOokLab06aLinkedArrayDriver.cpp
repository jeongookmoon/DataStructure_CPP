// Lab 6a, Writing a Linked Array Class Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express


#include <iostream>
using namespace std;

#include "MoonJeongOokLab06aLinkedArray.h"

template <class T>
ostream & operator<<(ostream& show, const LinkedArray<T> & object) // cout elements stored in vector whatsinside
{
	vector<int> whatsinside = object.Keys();
	int size = whatsinside.size();
	for (int i = 0; i < size; i++)
	{
		show << "Keys : " << whatsinside[i] << ", Value : " << object[whatsinside[i]];
		if (i < size - 1)
			show << "\n";
	}

	return show;
}



int main()
{
	cout << "Lab 6a, Writing a Linked Array Class Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

	cout << "Creating a new object of the Linked Array called originalA........" << endl;

	LinkedArray<double> originalA;

	cout << "\nSize of the originalA is " << originalA.Size() << ", capacity is " << originalA.Capacity() << ", and the contents are " << endl;
	cout << originalA << endl;

	cout << "Putting random values into the object of the LinkedArray.. \nindex 1,8,27,48 .... values 32,10,8,291" << endl;
	
	originalA[1] = 32;
	originalA[8] = 10;
	originalA[27] = 8;
	originalA[48] = 291;
	
	cout << "\nSize of the originalA is " << originalA.Size() << ", capacity is " << originalA.Capacity() << ", and the contents are " << endl;
	cout << originalA << endl;
	
	cout << "\nCreating a new object of the Linked Array called cA to test ca(originalA)..." << endl;

	LinkedArray<double> cA(originalA);

	cout << "\nSize of the cA is " << cA.Size() << ", capacity is " << cA.Capacity() << ", and the contents are " << endl;
	cout << cA << endl;

	cout << "\nCreating a new object of the Linked Array called lA, to test la = originalA..." << endl;

	LinkedArray<double> lA;
	lA = originalA;

	cout << "\nSize of the lA is " << lA.Size() << ", capacity is " << lA.Capacity() << ", and the contents are " << endl;
	cout << lA << endl;

	cout << "\nCreating a new object of the Linked Array called originalB........" << endl;

	LinkedArray<double> originalB;

	cout << "\nSize of the originalB is " << originalB.Size() << ", capacity is " << originalB.Capacity() << ", and the contents are " << endl;
	cout << originalB << endl;

	cout << "Putting random values into the object of the LinkedArray.. \nindex 31,21,7,827 .... values 3,-2,42,0" << endl;

	originalB[31] = 3;
	originalB[21] = -2;
	originalB[7] = 42;
	originalB[827] = 0;

	cout << "\nSize of the originalB is " << originalB.Size() << ", capacity is " << originalB.Capacity() << ", and the contents are " << endl;
	cout << originalB << endl;

	cout << "\nTesting originalB = originalA (overwrite a=b test)..." << endl;

	originalB = originalA;

	cout << "\nSize of the originalA is " << originalA.Size() << ", capacity is " << originalA.Capacity() << ", and the contents are " << endl;
	cout << originalA << endl;

	cout << "\nSize of the originalB is " << originalB.Size() << ", capacity is " << originalB.Capacity() << ", and the contents are " << endl;
	cout << originalB << endl;

	cout << "\nKeys test. originalA keys are " << endl;
	{
		vector<int> keys;
		keys = originalA.Keys();
		int max = keys.size();
		for (int i = 0; i < max; i++)
		{
			cout << " " << keys[i];
			if (i < max - 1)
				cout << ", ";
		}
		cout << endl;
	}

	cout << "\nContainskey test for originalA ..." << endl;
	{
		unsigned int cap = originalA.Capacity();
		bool needcomma = false;
		cout << boolalpha;
		for (int i = 0; i < cap; i++)
		{
			if (originalA.ContainsKey(i) == true || i % 15 == 0)
			{
				cout << "originalA[" << i << "] " << originalA.ContainsKey(i);
				if (i < cap - 1)
					cout << "\n";
			}
		}
		cout << endl;
	}

	cout << "\nDeleteKey test for originalA ..." << endl;
	cout << "Size of the originalA is " << originalA.Size() << ", capacity is " << originalA.Capacity() << ", and the contents are " << endl;
	cout << originalA << endl;


	cout << "\nDeleting originalA[1] and originalA[27]..." << endl;
	
	originalA.DeleteKey(1);
	originalA.DeleteKey(27);

	cout << "\nSize of the originalA is " << originalA.Size() << ", capacity is " << originalA.Capacity() << ", and the contents are " << endl;
	cout << originalA << endl;

	cout << "\nClear test on originalB ..." << endl;
	cout << "\nSize of the originalB is " << originalB.Size() << ", capacity is " << originalB.Capacity() << ", and the contents are " << endl;
	cout << originalB << endl;
	cout << "\nClearing originalB ..." << endl;
	originalB.Clear();
	cout << "\nSize of the originalB is " << originalB.Size() << ", capacity is " << originalB.Capacity() << ", and the contents are " << endl;
	cout << originalB << endl;

	cin.get();
}