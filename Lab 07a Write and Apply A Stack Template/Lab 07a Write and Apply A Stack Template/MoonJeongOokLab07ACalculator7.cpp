// Lab 7a, Writing and applying a stack template
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <string>
#include "MoonJeongOokLab07AStack.h"

using namespace std;

template <class T>
void PrintStack(Stack<T> astack)
{
	Stack<T> copy = astack;
	while (copy.Size() > 0)
	{
		double num;
		copy.Pop(num);
		cout << num;
		if (copy.Size() > 0)
			cout << ", ";
	}
}



int main()
{
	cout << "Lab 7A, Writing and Applying A Stack Template\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Calculator 7 Using A Stack Template\" program" << endl << endl;

	double operand1, operand2;
	Stack <double> hays;
	string user_value;
	double num1, num2, peekvalue;
	cout << "Enter a value: ";
	while (true)
	{
		//getline(cin, user_value); // gets the first string to the first '\n' delimeter.
		cin >> user_value; // gets the first string == whitespace delimited string ' ' is a whitespace ' ','\t', 
		if (user_value == "+")
		{

			hays.Pop(num1);
			hays.Pop(num2);
			hays.Push(num1 + num2);
			hays.Peek(peekvalue);
			cout << "Result of " << num1 << " + " << num2 << " is " << peekvalue << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "-")
		{

			hays.Pop(num1);
			hays.Pop(num2);
			hays.Push(num1 - num2);
			hays.Peek(peekvalue);
			cout << "Result of " << num1 << " - " << num2 << " is " << peekvalue << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "*")
		{

			hays.Pop(num1);
			hays.Pop(num2);
			hays.Push(num1 * num2);
			hays.Peek(peekvalue);
			cout << "Result of " << num1 << " * " << num2 << " is " << peekvalue << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "/")
		{

			hays.Pop(num1);
			hays.Pop(num2);
			hays.Push(num1 / num2);
			hays.Peek(peekvalue);
			cout << "Result of " << num1 << " / " << num2 << " is " << peekvalue << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "q" || user_value == "Q")
		{
			cout << "Bye" << endl;

			break;
		}
		else
		{
			hays.Push(atof(user_value.c_str()));
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}

		cin.get();
	}
}