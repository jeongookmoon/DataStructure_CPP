#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <vector>
using namespace std;

template <class T>
class DynamicArray
{

private:
	// Dynamic array of data elements
	T * data;
	// true if the corresponding data element is in use, 
	// false if not in use
	bool * in_use;
	// Counts in use elements
	unsigned int size;
	// Total elements available
	unsigned int cap;
	T dummy;
public:
	// Must haves for dynamic memory usage
	DynamicArray();
	DynamicArray( const DynamicArray<T> & );
	virtual ~DynamicArray();
	DynamicArray<T> & operator=( const DynamicArray<T> &);
	// Methods

	// operator[]const
	//   read only access to elements
	//   returns dummy if index is not in use
	T operator[](unsigned int index)const;

	// operator[]
	//   r/w access to elements
	//   marks element to in use
	//   extends array if element does not exist
	T& operator[](unsigned int index);

	// Size()
	//   returns the number of in-use elements
	unsigned int Size()const;

	// Capacity()
	//   returns the allocated size in elements
	unsigned int Capacity()const;

	// bool ContainsKey( index )
	//   true if the passed index is in bounds and in use
	//   false if not in bounds or not in use
	bool ContainsKey(unsigned int index)const;

	// DeleteKey( index )
	//   Marks the indicated element as not in use, if
	//     the element exists.
	//   Nothing happens if the index is out of bounds.
	void DeleteKey(unsigned int index);

	// Keys()
	//   returns a STL vector of in-use indices.
	vector<unsigned int> Keys()const;

	// Clear()
	//   sets all indices to not in use.
	//   array remains same capacity
	void Clear();
private:
	// Helper methods

	// DeepCopy
	//   Assumes no dynamic memory to clean up 
	//     before allocating new memory
	void Copy( const DynamicArray<T> & );

	// DeepDestruct.
	//   dynamic array pointers are null after 
	//     destruction.
	void Delete();

	// SetCapacity
	//   resets array to the passed capacity
	//   copies applicable elements and 
	//     associated in-use status
	void SetCapacity( unsigned int newCap = 10 );
};


// Must haves for dynamic memory usage
template <class T>
DynamicArray<T>::	DynamicArray()
	:data(NULL),in_use(NULL),size(0),cap(0)
{
}
template <class T>
DynamicArray<T>::	DynamicArray( const DynamicArray<T> & aArray )
	:data(NULL),in_use(NULL)
{
	Copy(aArray);
}
template <class T>
DynamicArray<T>::	~DynamicArray()
{
	Delete();
}
template <class T>
DynamicArray<T> & DynamicArray<T>::operator=( const DynamicArray<T> & aArray )
{
	if( this != & aArray )
	{
		Delete();
		Copy(aArray);
	}
	return *this;
}

// Methods

// operator[]const
//   read only access to elements
//   returns dummy if index is not in use
template <class T>
T DynamicArray<T>::operator[](unsigned int index)const
{
	if( index >= cap )
		return dummy;
	return data[index];
}

// operator[]
//   r/w access to elements
//   marks element to in use
//   extends array if element does not exist
template <class T>
T& DynamicArray<T>::operator[](unsigned int index)
{
	if ( index+1 > cap )
	{
		SetCapacity(index+1);
	}
	if( ! in_use[index] ) size++;
	in_use[index] = true;
	return data[index];
}

// Size()
//   returns the number of in-use elements
template <class T>
unsigned int DynamicArray<T>::Size()const
{
	return size;
}

// Capacity()
//   returns the allocated size in elements
template <class T>
unsigned int DynamicArray<T>::Capacity()const
{
	return cap;
}

// bool ContainsKey( index )
//   true if the passed index is in bounds and in use
//   false if not in bounds or not in use
template <class T>
bool DynamicArray<T>::ContainsKey(unsigned int index)const
{
	if( index < cap )
		return in_use[index];
	return false;
}

// DeleteKey( index )
//   Marks the indicated element as not in use, if
//     the element exists.
//   Nothing happens if the index is out of bounds.
template <class T>
void DynamicArray<T>::DeleteKey(unsigned int index)
{
	if( index < cap )
	{
		if( in_use[index] )
		{
			size--;
			in_use[index] = false;
		}
	}
}

// Keys()
//   returns a STL vector of in-use indices.
template <class T>
vector<unsigned int> DynamicArray<T>::Keys()const
{
	vector<unsigned int> indices;
	for( unsigned int i = 0; i < cap; ++i )
	{
		if( in_use[i] )
			indices.push_back(i);
	}
	return indices;
}

// Clear()
//   sets all indices to not in use.
//   array remains same capacity
template <class T>
void DynamicArray<T>::Clear()
{
	for( unsigned int i = 0; i < cap; ++i )
		in_use[i] = false;
}

// Helper methods

// DeepCopy
	//   Assumes no dynamic memory to clean up 
	//     before allocating new memory
template <class T>
void DynamicArray<T>::Copy( const DynamicArray<T> & aArray )
{
	size = aArray.size;
	cap = aArray.cap;
	data = new T[cap];
	in_use = new bool[cap];
	for( unsigned int i = 0; i < cap; ++i )
	{
		in_use[i] = false;
		if( aArray.in_use[i] )
		{
			in_use[i] = true;
			data[i] = aArray.data[i];
		}
	}
}

// DeepDestruct.
//   dynamic array pointers are null after destruction
template <class T>
void DynamicArray<T>::Delete()
{
	if( data )
	{
		delete [] data;
		data = NULL;
	}
	if( in_use )
	{
		delete in_use;
		in_use = NULL;
	}
	size = cap = 0;
}

// SetCapacity
//   resets array to the passed capacity
//   copies applicable elements and 
//     associated in-use status
template <class T>
void DynamicArray<T>::SetCapacity( unsigned int newCap = 10 )
{
	if ( newCap == 0 )
	{
		Delete();
		return;
	}

	T * newData = new T[newCap];
	bool * newInUse = new bool[newCap];
	size = 0;

	unsigned int upperLimit = cap < newCap ? cap : newCap;
	for( unsigned int i = 0; i < upperLimit; ++i )
	{
		newInUse[i] = in_use[i];
		if( in_use[i] )
		{
			size++;
			newData[i] = data[i];
		}
	}
	if( upperLimit < newCap )
	{
		for( unsigned int i = upperLimit; i < newCap; ++i )
		{
			newInUse[i] = false;
		}
	}

	cap = newCap;
	if ( data )
		delete [] data;
	if ( in_use )
		delete [] in_use;
	data = newData;
	in_use = newInUse;
}


#endif