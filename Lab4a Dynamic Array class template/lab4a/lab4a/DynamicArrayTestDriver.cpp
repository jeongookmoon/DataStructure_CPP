
#include <iostream> // for cout, <<, ostream
#include <array>    // for array
#include <stack>    // for stack
#include <string>   // for string, getline, >>
#include <cstdlib>	// for srand, rand
#include <ctime>    // for time
#include "DynamicArray.h"
using namespace std;


template <class T>
ostream & operator<<( ostream & os, const DynamicArray<T> & aArray )
{
	os << "(";
	vector<unsigned int> indices = aArray.Keys();
	for( unsigned int i = 0; i < indices.size(); ++i)
	{
		cout << "{" << indices[i] << ": " <<
			aArray[indices[i]] << "}";
		if( i < indices.size()-1 )
			cout << ", ";
	}
	os << ")";
	return os;
}

void DynamicArrayTest()
{
	//	// Must haves for dynamic memory usage

	//DynamicArray();
	DynamicArray<string> sA;
	cout << "Default cotr test: " << endl;
	cout << "sA: " << sA << endl << endl;


	cout << "Random String Inserts: " << endl;
	sA[23] = "Atoz";
	sA[72] = "cmx";
	sA[3] = "slq";
	sA[17] = "!akq";
	cout << "sA: " << sA << endl << endl;

	//DynamicArray( const DynamicArray<T> & );
	cout << "Copy cotr: " << endl;
	const DynamicArray<string> csB(sA);
	cout << "csB: " << csB << endl << endl;

	//virtual ~DynamicArray();
	//DynamicArray<T> & operator=( const DynamicArray<T> &);
	cout << "Assignment test: " << endl;
	DynamicArray<string> sC;
	sC[27] = "sadjk";
	sC[11] = "xcj";
	sC[1] = "2ds";

	cout << "(before) sC: " << sC << endl;
	cout << "sC = sA" << endl;
	sC = sA;
	cout << "(after) sC: " << sC << endl << endl;

	//// Methods

	//// operator[]const
	////   read only access to elements
	////   returns dummy if index is not in use
	//T operator[](unsigned int index)const;
	cout << "[] const test: " << endl;
	cout << "csB (first 10): (";
	bool needComma;
	needComma = false;
	for( unsigned int i = 0; i < 10; ++i )
	{
		if( csB.ContainsKey( i ) )
		{
			if ( needComma )
				cout << ", ";
			needComma = true;
			cout << "{" << i << ": ";
			cout << csB[i] << "}";
		}
	}
	cout << ")" << endl << endl;

	//// Size()
	////   returns the number of in-use elements
	//unsigned int getSize()const;
	cout << "Size() test: " << endl;
	cout << "sA.Size(): " << sA.Size() << endl;
	cout << "csB.Size(): " << csB.Size() << endl;
	cout << "sC.Size(): " << sC.Size() << endl << endl;

	//// Capacity()
	////   returns the allocated size in elements
	//unsigned int getCapacity()const;
	cout << "Capacity() test: " << endl;
	cout << "sA.Capacity(): " << sA.Capacity() << endl;
	cout << "csB.Capacity(): " << csB.Capacity() << endl;
	cout << "sC.Capacity(): " << sC.Capacity() << endl << endl;

	//// bool ContainsKey( index )
	////   true if the passed index is in bounds and in use
	////   false if not in bounds or not in use
	//bool ContainsKey(unsigned int index)const;
	cout << "ContainsKey test: " << endl;
	cout << "sC (first 10): (";
	needComma = false;
	for( unsigned int i = 0; i < 10; ++i )
	{
		if ( needComma )
			cout << ", ";
		needComma = true;
		if( sC.ContainsKey( i ) )
		{
			cout << "{" << i << ": ";
			cout << sC[i] << "}";
		}
		else
		{
			cout << "{" << i << ": Empty}";
		}
	}
	cout << ")" << endl << endl;

	//// DeleteKey( index )
	////   Marks the indicated element as not in use, if
	////     the element exists.
	////   Nothing happens if the index is out of bounds.
	//void DeleteKey(unsigned int index);
	cout << "DeleteKey test: " << endl;
	for( unsigned int i = 0; i < sC.Size(); ++i )
	{
		if( sC.ContainsKey(i) )
		{
			sC.DeleteKey(i);
			cout << "Deleted key " << i << endl;
			break;
		}
	}
	needComma = false;
	cout << "sC (first 10 after delete): (";
	for( unsigned int i = 0; i < 10; ++i )
	{
		if ( needComma )
			cout << ", ";
		needComma = true;
		if( sC.ContainsKey( i ) )
		{
			cout << "{" << i << ": ";
			cout << sC[i] << "}";
		}
		else
		{
			cout << "{" << i << ": Empty}";
		}
	}
	cout << ")" << endl << endl;

	//// Keys()
	////   returns a STL vector of in-use indices.
	//vector<unsigned int> Keys()const;
	cout << "Keys test: " << endl;
	vector<unsigned int> indices;
	indices = sC.Keys();
	cout << "sC keys: ";
	needComma = false;
	for( unsigned int i = 0; i < indices.size(); ++i )
	{
		if( needComma ) cout << ", ";
		needComma = true;
		cout << indices[i];
	}
	cout << endl << endl;

	//// Clear()
	////   sets all indices to not in use.
	////   array remains same capacity
	//void Clear();
	cout << "Clear test: " << endl;
	sC.Clear();
	cout << sC << endl << endl;
}

int main()
{
	DynamicArrayTest();

	cout << "Please enter" << endl;
	cin.get();
}