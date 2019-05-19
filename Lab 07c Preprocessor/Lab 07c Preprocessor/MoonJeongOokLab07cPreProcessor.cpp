// Lab 7c, Using a Stack
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express



#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

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
	cout << "Lab 7c, Using a Stack\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"PreProcessor\" program" << endl << endl;

	cout << "Please enter the name of the file" << endl;
	string filename;
	getline(cin, filename);

	cout << "Please enter a type name ( H, CPP, JAVA, HTML, JS, OR TXT)" << endl;
	string type;
	getline(cin, type);

	ifstream fin;
	string fullname = filename + "." + type;
	fin.open(fullname);

	if (!fin.good())
		throw(exception(" Error : Can't open the file! "));

	Stack<string> commentoffsets;

	int lineCounter = 0;
	int match = 0;
	int mismatchopening = 0;
	int mismatchclosing = 0;
	while (fin.good())
	{
		string line;
		getline(fin, line);
		lineCounter++;
		unsigned int index = 0;
		
		for (index; index < line.length(); index++)
		{

			char check = line[index];
			char check2 = line[index + 1];
			if (check == '/')
			{
				if (check2 == '*')
				{
					if (commentoffsets.isEmpty() == true)
					{
						string first(1, check);
						string second(1, check2);
						string input = first + second;
						commentoffsets.Push(input);
						cout << "Opening comment offset is found in line " << lineCounter << " of " << fullname << endl;
					}
					else if (commentoffsets.isEmpty() == false)
					{
						mismatchopening++;
					}
				}
			}
			else if (check == '*')
			{
				if (check2 == '/')
				{
					if (commentoffsets.isEmpty() == false)
					{
						string inside;
						commentoffsets.Pop(inside);
						cout << "Matched closing comment offset is found in line " << lineCounter << " of " << fullname << endl;
						match++;
						mismatchopening = 0;
					}
					else if (commentoffsets.isEmpty() == true)
					{
						cout << "Mismatched closing comment offset is found in line " << lineCounter << " of " << fullname << endl;
						mismatchclosing++;
					}
				}
			}
		}
	}
	
	if (match == 0)
		cout << "There's no match for comment offsets" << endl;
	if (match > 0)
		cout << "There are " << match << " matched comment offsets" << endl;
	if (mismatchopening != 0)
		if (commentoffsets.isEmpty() == true)
		{
			cout << "There are " << mismatchopening << " mismatched opening comment offsets" << endl;
		}
		else if (commentoffsets.isEmpty() == false)
		{
			cout << "There are " << mismatchopening+1 << " mismatched opening comment offsets" << endl;
		}
	if (mismatchclosing != 0)
		cout << "There are " << mismatchclosing << " mismatched closing comment offsets" << endl;
	fin.close();
	cout << endl;
	ifstream fin2;
	fin2.open(fullname);

	if (!fin2.good())
		throw(exception(" Error : Can't open the file! "));

	Stack<char> parentheses;

	lineCounter = 0;
	match = 0;
	mismatchopening = 0;
	mismatchclosing = 0;
	
	while (fin2.good())
	{
		string line;
		getline(fin2, line);
		lineCounter++;
		for (unsigned int index = 0; index < line.length(); index++)
		{
			char check = line[index];

			if (parentheses.isEmpty() == true)
			{
				if (check == '(')
				{
					parentheses.Push(check);
					cout << "Opening parethesis is found in line " << lineCounter << " of " << fullname << endl;
				}
				else if (check == ')')
				{
					cout << "Mismatched closing parethesis is found in line " << lineCounter << " of " << fullname << endl;
					mismatchclosing++;
				}
			}
			else if (parentheses.isEmpty() == false)
			{
				if (check == ')')
				{
					parentheses.Pop(check);
					cout << "Matched closing parenthesis is found in line " << lineCounter << " of " << fullname << endl;
					match++;
				}
				else if (check == '(')
				{
					parentheses.Push(check);
					cout << "Opening parethesis is found in line " << lineCounter << " of " << fullname << endl;
				}
			}
		}
	}
	if (match == 0)
		cout << "There's no match for parenthesis" << endl;
	if (match > 0)
		cout << "There are " << match << " matched parentheses" << endl;
	
	if (parentheses.isEmpty() == false)
		{
			cout << "There are " << parentheses.Size() << " mismatched opening parentheses" << endl;
		}

	if (mismatchclosing != 0)
		cout << "There are " << mismatchclosing << " mismatched closing comment offsets" << endl;
	fin2.close();

	cout << endl;
	ifstream fin3;
	fin3.open(fullname);

	if (!fin3.good())
		throw(exception(" Error : Can't open the file! "));

	Stack<char> curlybraces;

	lineCounter = 0;
	match = 0;
	mismatchopening = 0;
	mismatchclosing = 0;

	while (fin3.good())
	{
		string line;
		getline(fin3, line);
		lineCounter++;
		for (unsigned int index = 0; index < line.length(); index++)
		{
			char check = line[index];

			if (curlybraces.isEmpty() == true)
			{
				if (check == '{')
				{
					curlybraces.Push(check);
					cout << "Opening curly brace is found in line " << lineCounter << " of " << fullname << endl;
				}
				else if (check == '}')
				{
					cout << "Mismatched closing curly brace is found in line " << lineCounter << " of " << fullname << endl;
					mismatchclosing++;
				}
			}
			else if (curlybraces.isEmpty() == false)
			{
				if (check == '}')
				{
					curlybraces.Pop(check);
					cout << "Matched closing curly brace is found in line " << lineCounter << " of " << fullname << endl;
					match++;
				}
				else if (check == '{')
				{
					curlybraces.Push(check);
					cout << "Opening curly brace is found in line " << lineCounter << " of " << fullname << endl;
				}
			}
		}
	}
	if (match == 0)
		cout << "There's no match for curly brace" << endl;
	if (match > 0)
		cout << "There are " << match << " matched curly braces" << endl;

	if (curlybraces.isEmpty() == false)
	{
		cout << "There are " << curlybraces.Size() << " mismatched opening curly braces" << endl;
	}

	if (mismatchclosing != 0)
		cout << "There are " << mismatchclosing << " mismatched closing curly braces" << endl;
	fin3.close();

	cout << endl;
	ifstream fin4;
	fin4.open(fullname);

	if (!fin4.good())
		throw(exception(" Error : Can't open the file! "));

	Stack<char> squarebrackets;

	lineCounter = 0;
	match = 0;
	mismatchopening = 0;
	mismatchclosing = 0;

	while (fin4.good())
	{
		string line;
		getline(fin4, line);
		lineCounter++;
		for (unsigned int index = 0; index < line.length(); index++)
		{
			char check = line[index];

			if (squarebrackets.isEmpty() == true)
			{
				if (check == '[')
				{
					squarebrackets.Push(check);
					cout << "Opening square bracket is found in line " << lineCounter << " of " << fullname << endl;
				}
				else if (check == ']')
				{
					cout << "Mismatched closing square bracket is found in line " << lineCounter << " of " << fullname << endl;
					mismatchclosing++;
				}
			}
			else if (squarebrackets.isEmpty() == false)
			{
				if (check == ']')
				{
					squarebrackets.Pop(check);
					cout << "Matched closing square bracket is found in line " << lineCounter << " of " << fullname << endl;
					match++;
				}
				else if (check == '[')
				{
					squarebrackets.Push(check);
					cout << "Opening square bracket is found in line " << lineCounter << " of " << fullname << endl;
				}
			}
		}
	}
	if (match == 0)
		cout << "There's no match for square bracket" << endl;
	if (match > 0)
		cout << "There are " << match << " matched square brackets" << endl;

	if (squarebrackets.isEmpty() == false)
	{
		cout << "There are " << squarebrackets.Size() << " mismatched opening square brackets" << endl;
	}

	if (mismatchclosing != 0)
		cout << "There are " << mismatchclosing << " mismatched closing square brackets" << endl;
	fin4.close();

	cout << endl;
	ifstream fin5;
	fin5.open(fullname);

	if (!fin5.good())
		throw(exception(" Error : Can't open the file! "));

	Stack<char> quotes;

	lineCounter = 0;
	match = 0;
	unsigned int mismatch = 0;
	mismatchclosing = 0;
	bool quoteEmpty = true;


	while (fin5.good())
	{
		string line;
		getline(fin5, line);
		lineCounter++;
		unsigned int index = 0;
		for (index; index < line.length(); index++)
		{
			char check = line[index];

			if (quotes.isEmpty() == true)
			{
				if (check == '"')
				{
					quotes.Push(check);
					cout << "Opening quotation mark is found in line " << lineCounter << " of " << fullname << endl;
				}
			}
			else if (quotes.isEmpty() == false)
			{
				if (check == '"')
				{
					char value;
					quotes.Pop(value);
					cout << "Matched closing quotation mark is found in line " << lineCounter << " of " << fullname << endl;
					match++;
				}
			}
		}
	if (quotes.isEmpty() == false)
		{
			mismatch++;
			cout << "Mismatched quotation mark remains in line " << lineCounter << " of " << fullname << endl;
			char value;
			quotes.Pop(value);
		}
	}
	if (match == 0)
		cout << "There's no match for quotation marks" << endl;
	if (match > 0)
		cout << "There are " << match << " matched quotation marks" << endl;
	if (mismatch > 0)
		cout << "There are " << mismatch << " mismatched quotation marks" << endl;
	
	fin5.close();


	cin.get();
	
	
}
