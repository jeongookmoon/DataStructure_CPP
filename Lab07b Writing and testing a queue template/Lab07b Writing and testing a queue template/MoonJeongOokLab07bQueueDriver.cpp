// Lab 7b, Writing and testing a queue template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include "MoonJeongOokLab07bQueue.h"
#include <vector>

using namespace std;

template <class T>
ostream & operator<<(ostream& os, const Queue<T> & a_list)
{
	Queue<T> copyList;
	copyList = a_list;
	unsigned int max = copyList.Size();
	for (int i=0; i < max; i++)
	{
		cout << "( index : " << i << ", value : " << copyList.peek() << " )" << endl;
		copyList.deQueue();
	}

	return os;
}

int main()
{
	cout << "Lab 7b, Writing and testing a queue template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing and testing a queue template\" program" << endl << endl;
	

	
	Queue<double> originalA;
	cout << "\nCreating instance of the Queue<double> called  originalA   ....." << endl;
	cout << "\n:::: Size() test ::::" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;



	cout << "\nPutting 11 random values into originalA by enQueue() .... \n(values are 32, 2, -10, 301, 291, 42, 78, 92, 192, 382, 3)" << endl;

	originalA.enQueue(32);
	originalA.enQueue(2);
	originalA.enQueue(-10);
	originalA.enQueue(301);
	originalA.enQueue(291);
	originalA.enQueue(42);
	originalA.enQueue(78);
	originalA.enQueue(92);
	originalA.enQueue(192);
	originalA.enQueue(382);
	originalA.enQueue(3);

	cout << "\n:::: Size() test ::::\n(after putting 11 values by enQueue(),\nexpected size of originalA is 11) " << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;

	cout << "\nCopy constructor test, Creating instance of the Queue<double> called  copyB and make it equal to originalA \nby Queue<double> copyB = originalA ....." << endl;
	Queue<double> copyB = originalA; // copy constructor
																	 

	cout << "\nShowing values inside copyB ....." << endl;
	cout << copyB << endl;

	cout << "\nCreating instance of the Queue<double> called  copyC and make it equal to originalA \nby copyc = originalA (assignment operator)....." << endl;
	Queue<double> copyC;
	copyC = originalA;

	cout << "\nShowing values inside copyC ....." << endl;
	cout << copyC << endl;

	cout << "\nRemoving first 3 values inside originalA by deQueue()....." << endl;
	originalA.deQueue();
	originalA.deQueue();
	originalA.deQueue();

	cout << "Since 32, 2, -10 were the first 3 values, these three should be removed" << endl;
	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	cout << "Since 3 things got removed, size should be 8" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;
	cout << "\nTesting Peek()....." << endl;
	cout << "doing originalA.peek().....\nSince 301 is the oldest value the peek should show 301, and peek() is " << originalA.peek() << endl;




	cin.get();
}
