// Lab 2C, Writing Templates And Overloading Operators
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2013 Express
// Compiler(s) used: VC++ 2013 Express

#include <iostream>
using namespace std;

class MyStack
{
private:

	int length;
	int top;
	char stack[20];

public:
	MyStack()
	{
		top = -1;
		length = 20;
	}
	bool isEmpty() const
	{
		return (top == -1);
	}
	bool isFull() const
	{
		return (top == (length - 1));
	}

	void push(char c)
	{
		if (isFull())
			return;
		top++;
		stack[top] = c;

	}
	void pop(char& c)
	{
		if (isEmpty())
			return;
		c = stack[top];
		top--;
	}
	void dump() const
	{
		cout << "Array : ";
		for (int i = 0; i < length; i++)
			cout << stack[i] << " ";
		cout << endl;

		cout << "TOP: " << top << endl;

		cout << "STACK: ";

		for (int i = 0; i < top; i++)
			cout << stack[i] << " ";
		cout << endl;
	}
};


int main()
{
	MyStack s;
	char t;
	while (!s.isEmpty())
	{
		s.pop(t);
		cout << t << " ";
	}
	cout << endl;
	cout << "----" << endl;
	s.dump();

	cout << "Enter" << endl;
	cin.get();
}

/*
string token;  // global variable

for each token in the expression do:
if token is a number then
push it onto the stack
else if token is "+" then
pop the top 2 elements of the stack; call them a and b
push a + b onto the stack
else if token is "*" then
pop the top 2 elements of the stack; call them a and b
push a * b onto the stack
else if token is "-" then
pop the top 2 elements of the stack; call them a and b
push a - b onto the stack
else if token is "/" then
pop the top 2 elements of the stack; call them a and b
push a / b onto the stack

while (cin >> token) {
if (token == "+") {
// pop the top two elements of the stack
// the top element is b, and the one under the top is a
double b = pop();
double a = pop();
push(a + b);
// print the top of the stack so we can see the result
cout << "tos = " << stack.back() << "\n";
} else if (token == "-") {
double b = pop();
double a = pop();
push(a - b);
cout << "tos = " << stack.back() << "\n";
} else if (token == "*") {
double b = pop();
double a = pop();
push(a * b);
cout << "tos = " << stack.back() << "\n";
} else if (token == "/") {
double b = pop();
double a = pop();
push(a / b);
cout << "tos = " << stack.back() << "\n";
} else {
push(string_to_double(token));
}

while (cin >> token) {
if (token == "+" || token == "-" || token == "*" || token == "/")
cout << "'" << token << "' is an operator\n";
else
cout << token << " is (perhaps) a number\n";
}

*/
