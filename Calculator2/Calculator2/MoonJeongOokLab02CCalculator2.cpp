// Lab 2C, Using Templated Classes
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
void PrintStack(stack<T> astack)
{
	stack<T> copy = astack;
	while (copy.size() > 0)
	{
		cout << copy.top();
		copy.pop();
		if (copy.size() > 0)
			cout << ", ";
	}
}



int main()
{
	double operand1, operand2;
	stack <double> hays;
	string user_value;
	cout << "Enter a value: ";
	while (true)
	{
		cin >> user_value;
		if (user_value == "+")
		{
			operand2 = hays.top();
			hays.pop();
			operand1 = hays.top();
			hays.pop();
			hays.push(operand1 + operand2);
			cout << "Result of " << operand1 << " + " << operand2 << " is " << hays.top() << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "-")
		{
			operand2 = hays.top();
			hays.pop();
			operand1 = hays.top();
			hays.pop();
			hays.push(operand1 - operand2);
			cout << "Result of " << operand1 << " - " << operand2 << " is " << hays.top() << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "*")
		{
			operand2 = hays.top();
			hays.pop();
			operand1 = hays.top();
			hays.pop();
			hays.push(operand1 * operand2);
			cout << "Result of " << operand1 << " * " << operand2 << " is " << hays.top() << endl;
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
		}
		else if (user_value == "/")
		{
			operand2 = hays.top();
			hays.pop();
			operand1 = hays.top();
			hays.pop();
			hays.push(operand1 / operand2);
			cout << "Result of " << operand1 << " / " << operand2 << " is " << hays.top() << endl;
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
			hays.push(atof(user_value.c_str()));
			cout << "Enter a value: ";
			PrintStack(hays);
			cout << " ";
			//cout << endl;
		}
	}
	cout << "Press enter" << endl;
	cin.get();
}