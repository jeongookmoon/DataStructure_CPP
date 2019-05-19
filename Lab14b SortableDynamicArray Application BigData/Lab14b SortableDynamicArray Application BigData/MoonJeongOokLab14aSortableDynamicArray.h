#ifndef MOONJEONGOOKLAB14ASORTABLEDynamicArray_H
#define MOONJEONGOOKLAB14ASORTABLEDynamicArray_H

#include <vector>
#include <stack>
#include <utility>
using namespace std;

template <class T>
class SortableDynamicArray
{
private:
	static const int INIT_CAP = 100;
	unsigned int cap;
	T* values;
	bool* inUse;
	T dummy;
	int size;
	void Copy(const SortableDynamicArray<T> &);
	void Delete();
	void SetCapacity(unsigned int INIT_CAP);

public:

	SortableDynamicArray(int=INIT_CAP);
	SortableDynamicArray(const SortableDynamicArray<T> &);
	virtual ~SortableDynamicArray();
	SortableDynamicArray<T> & operator=(const SortableDynamicArray<T> &);
	T operator[](unsigned int index)const;
	T& operator[](unsigned int index);
	unsigned int Size()const;
	unsigned int Capacity()const;
	bool ContainsKey(unsigned int index)const;
	void DeleteKey(unsigned int index);
	vector<unsigned int> Keys()const;
	void Clear();
	void Sort(int); // int parameter specifies how many elements to sort, starting from element zero to this "fill-line"
	int BinarySearch(int, const T&) const;
};


template <class T>
SortableDynamicArray<T>::SortableDynamicArray(int init_cap)
{
	cap = init_cap;
	values = new T[cap];
	inUse = new bool[cap];
	size = 0;
	for (int i = 0; i < cap; i++)
		inUse[i] = false;
}

template <class T>
SortableDynamicArray<T>::SortableDynamicArray(const SortableDynamicArray<T> & a)
{
	values = NULL;
	inUse = NULL;
	Copy(a);
}
template <class T>
SortableDynamicArray<T>::~SortableDynamicArray()
{
	Delete();
}

template <class T>
SortableDynamicArray<T> & SortableDynamicArray<T>::operator=(const SortableDynamicArray<T> & a)
{
	if (this != &a)
	{
		Delete();
		Copy(a);
	}
	return *this;
}

template <class T>
T SortableDynamicArray<T>::operator[](unsigned int index)const
{
	if (index >= cap)
		return dummy;
	return values[index];
}

template <class T>
T& SortableDynamicArray<T>::operator[](unsigned int index)
{
	if (index + 1 > cap)
	{
		SetCapacity(index + 1);
	}
	if (!inUse[index]) size++;
	inUse[index] = true;
	return values[index];
}

template <class T>
unsigned int SortableDynamicArray<T>::Size()const
{
	return size;
}

template <class T>
unsigned int SortableDynamicArray<T>::Capacity()const
{
	return cap;
}

template <class T>
bool SortableDynamicArray<T>::ContainsKey(unsigned int index)const
{
	if (index < cap)
		return inUse[index];
	return false;
}

template <class T>
void SortableDynamicArray<T>::DeleteKey(unsigned int index)
{
	if (index < cap)
	{
		if (inUse[index])
		{
			size--;
			inUse[index] = false;
		}
	}
}

template <class T>
vector<unsigned int> SortableDynamicArray<T>::Keys()const
{
	vector<unsigned int> a;
	for (unsigned int i = 0; i < cap; ++i)
	{
		if (inUse[i])
			a.push_back(i);
	}
	return a;
}

template <class T>
void SortableDynamicArray<T>::Clear()
{
	for (unsigned int i = 0; i < cap; ++i)
		inUse[i] = false;
}

template <class T>
void SortableDynamicArray<T>::Copy(const SortableDynamicArray<T> & object)
{
	size = object.size;
	cap = object.cap;
	values = new T[cap];
	inUse = new bool[cap];

	for (unsigned int i = 0; i < cap; ++i)
	{
		inUse[i] = false;
		if (object.inUse[i])
		{
			inUse[i] = true;
			values[i] = object.values[i];
		}
	}
}
template <class T>
void SortableDynamicArray<T>::Delete()
{
	if (values)
	{
		delete[] values;
		values = NULL;
	}
	if (inUse)
	{
		delete inUse;
		inUse = NULL;
	}
	size = cap = 0;
}

template <class T>
void SortableDynamicArray<T>::SetCapacity(unsigned int newCap = 10)
{
	if (newCap == 0)
	{
		Delete();
		return;
	}

	T * newvalues = new T[newCap];
	bool * newInUse = new bool[newCap];
	size = 0;

	unsigned int upperLimit = cap < newCap ? cap : newCap;
	for (unsigned int i = 0; i < upperLimit; ++i)
	{
		newInUse[i] = inUse[i];
		if (inUse[i])
		{
			size++;
			newvalues[i] = values[i];
		}
	}
	if (upperLimit < newCap)
	{
		for (unsigned int i = upperLimit; i < newCap; ++i)
		{
			newInUse[i] = false;
		}
	}

	cap = newCap;
	if (values)
		delete[] values;
	if (inUse)
		delete[] inUse;
	values = newvalues;
	inUse = newInUse;
}

template <class T>
void SortableDynamicArray<T>::Sort(int numElements)
{
	//PUBLIC function with one parameter : #of elements to sort
	// quick sorting algorithm
	
	//	initialize s to the index of the FIRST element in the sorting range(zero)
	//	initialize e to the #of elements to sort

	int start = 0;
	int end = numElements;
	
	// stack is for queueing recursive cycles
	// put{ s, e } in stack
	// data array is "a"
	// notation: ai means a[i]
	
	stack<pair<int, int> > aStack;
	aStack.push(pair<int, int>(start, end));
	
	//   START RECURSIVE LOOP until stack is empty
	while (!aStack.empty())
	{
		//peek / pop the stack for s and e
		int start = aStack.top().first;
		int end = aStack.top().second;
		aStack.pop();

		//if (s >= e - 1) continue; // done with this cycle 
		if (start >= end - 1) continue;

		//int pivot = (s + e - 1) / 2; // right-side heavy 
		int pivot = (start + end - 1) / 2;

		//int left = s; // index of left-most element
		int left = start;

		//int right = e - 1; // index of right-most element
		int right = end - 1;

		//while (true)
		while (true)
		{
			//	while (left < pivot)
			while (left < pivot)
			{
				//		if (apivot < aleft) break; else ++left;
				if (values[pivot] < values[left])
					break;
				else
					++left;
			}
			
			//	while (pivot < right)
			while (pivot < right)
			{
				//		if (aright < apivot) break; else --right;
				if (values[right] < values[pivot])
					break;
				else
					--right;
			}
			
			//	if (left == right) // balanced and apivot is in the right place 
			if (left == right)
			{
				// stack recursive cycle with{ s, pivot }
				aStack.push(pair<int, int>(start, pivot));

				// stack recursive cycle with{ pivot + 1, e }
				aStack.push(pair<int, int>(pivot + 1, end));

				// break; // done with this cycle
				break;
			}

			//	else if (left == pivot) // swap w/pivot 
			else if (left == pivot)
			{
				// swap(apivot, aright)
				swap(values[pivot], values[right]);
				// pivot = right;
				pivot = right;
				// ++left;
				++left;
			}

			//	else if (pivot == right) // swap w/pivot 
			else if (pivot == right)
			{
				// swap(apivot, aleft)
				swap(values[left], values[pivot]);
				// pivot = left;
				pivot = left;
				// --right;
				--right;
			}

			//	else // swap around the pivot 
			else
			{
				// swap(aleft, aright)
				swap(values[left], values[right]);
				// ++left;
				++left;
				// --right;
				--right;
			}
		}
	}
}

template <class T>
int SortableDynamicArray<T>::BinarySearch(int numElements, const T& value) const
{
	int startIndex = 0;
	int endIndex = numElements;
	while (true)
	{		
		int midIndex = (startIndex + endIndex - 1) / 2;

		// got lucky -- matches middle element
		if (value == values[midIndex])
		{
			cout << "Found at index " << midIndex << endl;
			return midIndex;
			break;
		}
		// 1-element array
		else if (startIndex == (endIndex - 1))
		{
			cout << "There's no match" << endl; //only element in array did not match
			break;
		}
		// look between startIndex and endIndex-1
		else if (value < values[midIndex])
		{
			if (startIndex == midIndex)
			{
				cout << "There's no match" << endl; // but that range is empty, no match
				break;
			}
			// look in startIndex to midIndex-1	
			else
			{
				endIndex = midIndex;
				continue;
			}
		}
		else // look between midIndex+1 and endIndex-1
		{
			if (midIndex == (endIndex - 1))
			{
				cout << "There's no match" << endl; // but that range is empty, no match
				break;
			}
			else
			{
				startIndex = midIndex + 1; //look in midIndex-1 to endIndex
				continue;
			}
		}
	}
	return 0;
}


#endif
