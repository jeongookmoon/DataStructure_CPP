// Lab 11a, Writing And Testing A Priority Queue Template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>

#include "MoonJeongOokLab11aPriorityQueue.h"

using namespace std;

template <class T>
ostream & operator<<(ostream& show, const PriorityQueue<T> & rv_queue)
{
	PriorityQueue<T> copyQueue;
	copyQueue = rv_queue;
	unsigned int max = copyQueue.Size();
	for (int i = 0; i < max; i++)
	{
		cout << "( index : " << i << ", value : " << copyQueue.Top() << " )" << endl;
		copyQueue.Dequeue();
	}
	return show;
}


int main()
{
	cout << "Lab 11a, Writing And Testing A Priority Queue Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing And Testing A Priority Queue Template\" program" << endl << endl;

	PriorityQueue<double> originalA;
	cout << "\nCreating instance of the PriorityQueue<double> called  originalA" << endl;
	cout << "\n::Size() test" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;
	
	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	
	cout << "\nPutting 11 random values into originalA by Enqueue() .... \n(values are 32, 2, -10, 301, 291, 42, 78, 92, 192, 382, 3)" << endl;

	originalA.Enqueue(32);
	originalA.Enqueue(2);
	originalA.Enqueue(-10);
	originalA.Enqueue(301);
	originalA.Enqueue(291);
	originalA.Enqueue(42);
	originalA.Enqueue(78);
	originalA.Enqueue(92);
	originalA.Enqueue(192);
	originalA.Enqueue(382);
	originalA.Enqueue(3);
	
	cout << "\n::Size() test\n(after putting 11 values by Enqueue(), \nexpected size of originalA is 11) " << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;

	cout << "\n::Copy constructor test\nCreating instance of the PriorityQueue<double> called copyB\nand make it equal to originalA \nby PriorityQueue<double> copyB = originalA ....." << endl;
	PriorityQueue<double> copyB = originalA; // copy constructor


	cout << "\nShowing values inside copyB ....." << endl;
	cout << copyB << endl;

	cout << "\nCreating instance of the PriorityQueue<double> called copyC\nand make it equal to originalA \nby copyc = originalA (assignment operator)....." << endl;
	PriorityQueue<double> copyC;
	copyC = originalA;

	cout << "\nShowing values inside copyC ....." << endl;
	cout << copyC << endl;

	cout << "\nRemoving highest 3 values inside originalA by Dequeue()....." << endl;
	originalA.Dequeue();
	originalA.Dequeue();
	originalA.Dequeue();

	cout << "Since 382, 301, 291 were the highest 3 values, these three should be removed" << endl;
	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	cout << "Since 3 things got removed, size should be 8" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\nPutting 3 more values into originalA by Enqueue() .... \n(values are 621, 21, -564)" << endl;
	
	originalA.Enqueue(621);
	originalA.Enqueue(21);
	originalA.Enqueue(-564);
	
	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl; 
	cout << "Since 3 more values got added, size should be 11" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\nClear test" << endl;
	originalA.Clear();
	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	cout << "After originalA.Clear(), size should be 0" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;
	
	cin.get();
}