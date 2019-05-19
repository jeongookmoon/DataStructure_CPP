// Lab 7a, Writing and applying a stack template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <string>

#include "MoonJeongOokLab07AStack.h"


using namespace std;

template <class T>
ostream & operator<<(ostream& os, const Stack<T> & a_stack)
{
	Stack<T> copyStack;
	Stack<T> kcatSypoc;
	copyStack = a_stack;
	int i = 0;
	T value;

	while (!copyStack.isEmpty())
	{
		copyStack.Pop(value);
		kcatSypoc.Push(value);
	}

	while (!kcatSypoc.isEmpty())
	{
		kcatSypoc.Peek(value);
		cout << "( index : " << i++ << ", value : " << value << " )" << endl;
		kcatSypoc.Pop(value);
	}
	return os;
}

int main()
{
	cout << "Lab 7A, Writing and Applying A Stack Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing and Applying A Stack Template\" program" << endl << endl;

	Stack<double> originalA;
	cout << "\nCreating instance of the Stack<double> called  originalA   ....." << endl;
	cout << "\n:::: Size() test ::::" << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;
	
	cout << "\n:::: Capacity() test ::::\n(initial capacity is set as 10)" << endl;
	cout << "originalA.Capacity(): " << originalA.getCapacity() << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;

	cout << "\nPutting 11 random values into originalA by Push() .... \n(values are 32, 2, -10, 301, 291, 42, 78, 92, 192, 382, 3)" << endl;

	originalA.Push(32);
	originalA.Push(2);
	originalA.Push(-10);
	originalA.Push(301);
	originalA.Push(291);
	originalA.Push(42);
	originalA.Push(78);
	originalA.Push(92);
	originalA.Push(192);
	originalA.Push(382);
	originalA.Push(3);

	cout << "\n:::: Size() test ::::\n(after putting 11 values by Push(),\nexpected size of originalA is 11) " << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\n:::: Capacity() test ::::\n(Since I put more values than initial capacity(10),\nexpected capacity of originalA is 20 (doubled))" << endl;
	cout << "originalA.Capacity(): " << originalA.getCapacity() << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	

	cout << "\nCreating instance of the Stack<double> called  copyB and make it equal to originalA \nby Stack<double> copyB = originalA ....." << endl;
	Stack<double> copyB = originalA; // copy constructor
	// Stack<double> copyB; copyB = originalA; // default constructor; assignment operator
	
	cout << "\nShowing values inside copyB ....." << endl;
	cout << copyB << endl;

	cout << "\nCreating instance of the Stack<double> called  copyC and make it equal to originalA \nby copyc = originalA (assignment operator)....." << endl;
	Stack<double> copyC;
	copyC = originalA;

	cout << "\nShowing values inside copyC ....." << endl;
	cout << copyC << endl;
	
	cout << "\nRemoving 3 values inside originalA by Pop(parameter)....." << endl;
	
	cout.setf(ios_base::boolalpha);
	double num;

	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;
	
	cout << "\nTesting Peek(parameter)....." << endl;
	cout << "doing originalA.Peek(num), it's successful (" << originalA.Peek(num);
	cout << ") and num is " << num << endl;

	cout << "\n:::: Size() test ::::\n(after removing 3 values by Push(),\nexpected size of originalA is 8) " << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\n:::: Capacity() test ::::\nSize is greater than 1/4 of capacity,\nexpected capacity of originalA is still 20)" << endl;
	cout << "originalA.Capacity(): " << originalA.getCapacity() << endl;

	cout << "\nRemoving 4 more values inside originalA by Pop(parameter)....." << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;
	cout << "doing originalA.Pop(num), it's successful (" << originalA.Pop(num);
	cout << ") and num is " << num << endl;

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;

	cout << "\n:::: Size() test ::::\n(after removing 4 values by Push(),\nexpected size of originalA is 4) " << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\n:::: Capacity() test ::::\nSize is less than 1/4 of increased capacity,\nexpected capacity of originalA is 10)" << endl;
	cout << "originalA.Capacity(): " << originalA.getCapacity() << endl;

	cout << "\n:::: Clear() test ::::"<< endl;
	originalA.Clear();

	cout << "\nShowing values inside originalA ....." << endl;
	cout << originalA << endl;

	cout << "\n:::: Size() test ::::\nexpected size is 0 since it's been cleared." << endl;
	cout << "originalA.Size(): " << originalA.Size() << endl;

	cout << "\n:::: isEmpty() test ::::\nexpected result is true" << endl;
	cout << "originalA.isEmpty(): " << originalA.isEmpty() << endl;

	cout << "\n:::: Capacity() test ::::\nexpected capacity is 10" << endl;
	cout << "originalA.Capacity(): " << originalA.getCapacity() << endl;

	cout.unsetf(ios_base::boolalpha);

	cin.get();
}
