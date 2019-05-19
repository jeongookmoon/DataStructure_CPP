#ifndef MOONJEONGOOKLAB11APRIORITYQUEUE_H
#define MOONJEONGOOKLAB11APRIORITYQUEUE_H

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class PriorityQueue
{
private:
	T *PQarray;
	int size;
	int capacity;
	void doubleCap();
	T dummy;
	
public:
	PriorityQueue(int initialCapacity = 2);
	PriorityQueue(PriorityQueue<T> const &rv_array);
	PriorityQueue<T>& operator=(PriorityQueue<T> const & rv_array);
	virtual ~PriorityQueue();
	void Enqueue(const T&);
	T Top() const;
	T Dequeue();
	bool isEmpty() const;
	void Clear();			// Deletes dynamic memory. capacity is 0.
	void makeEmpty();		// Sets size to 0;
	int Size() const;
};
template <class T>
PriorityQueue<T>::PriorityQueue(int initialCapacity = 2)
{
	capacity = initialCapacity;
	PQarray = new T[capacity];
	size = 0;
	
}

template <class T>
PriorityQueue<T>::PriorityQueue(PriorityQueue<T> const &rv_array)
{
	capacity = rv_array.capacity;
	size = rv_array.size;
	PQarray = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		PQarray[i] = rv_array.PQarray[i];
	}
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue<T> const &rv_array)
{
	if (this != &rv_array)
	{
		if (PQarray != NULL)
		{
			delete[] PQarray;
		}
		size = rv_array.size;
		capacity = rv_array.capacity;
		PQarray = new T[capacity];
		for (int i = 0; i < size; i++)
			{
				PQarray[i] = rv_array.PQarray[i];
			}
	}
	return *this;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	if (PQarray != NULL)
	{
		delete[] PQarray;
	}
	PQarray = NULL;
	size = 0;
	capacity = 0;
}

template <class T>
void PriorityQueue<T>::Enqueue(const T &rv_value)
{
	int index = size;
	if (index >= capacity)
		doubleCap();
	PQarray[index] = rv_value;
	while (true)
	{
		int parentIndex = ((index + 1) / 2) - 1;
		if (parentIndex < 0)
			break;
		if (PQarray[parentIndex] >= PQarray[index])
			break;
		swap(PQarray[parentIndex], PQarray[index]);
		index = parentIndex;
	}
	size++;
		
	/*set index = size
	  if index >= capacity, double the capacity
	  copy new value into array at index
	  start loop
		parentIndex = (index + 1) / 2 - 1
		if parentIndex < 0, exit loop
		if value at parentIndex >= value at index, exit loop
		swap values at parentIndex and index
		set index = parentIndex
	  repeat to top of loop
	  increment size*/
}
template <class T>
T PriorityQueue<T>::Top() const
{
	if (size == 0)
	{
		return dummy;
	}
	return PQarray[0];
}

template <class T>
T PriorityQueue<T>::Dequeue()
{
	int index = 0;  // set index to zero
	int index_left;
	int index_right;
	T value = PQarray[0]; // save value at index 0 to return at end
	while (true) //start loop
	{
		index_left = 2 * index + 1; // index of left child = 2 * index + 1
		index_right = 2 * index + 2; // index of right child = 2 * index + 2
		if (index_left >= size) // if left child index >= size, exit loop
			break;
		if (index_left == (size - 1) || PQarray[index_left] >= PQarray[index_right]) // if left child index = size - 1
		{ // OR value of left child >= value of right child
			PQarray[index] = PQarray[index_left]; // set value at index to value of left child
			index = index_left; // set index = index of left child
		}
		else
		{
			PQarray[index] = PQarray[index_right]; // set value at index to value of right child
			index = index_right; // set index = index of right child
		}
	}
	size--; // decrement size
	PQarray[index] = PQarray[size]; // copy value at size into array at index
	while (true)  // start loop
	{
		int parentIndex = ((index + 1) / 2) - 1; // parentIndex = (index + 1) / 2 - 1
		if (parentIndex < 0) // if parentIndex < 0, exit loop
			break;
		if (PQarray[parentIndex] >= PQarray[index]) // if value at parentIndex >= value at index, exit loop
			break;
		swap(PQarray[index], PQarray[parentIndex]); // swap values at parentIndex and index
		index = parentIndex; // set index = parentIndex
	}
	return value; // return saved value*/
	
	
}

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
	return size == 0;
}
template <class T>
void PriorityQueue<T>::Clear()
{
	if (PQarray != NULL)
	{
		delete[] PQarray;
	}
	PQarray = NULL;
	size = 0;
	capacity = 0;
}
template <class T>
void PriorityQueue<T>::makeEmpty()		// Sets size to 0;
{
	size = 0;
}
template <class T>
int PriorityQueue<T>::Size() const
{
	return size;
}

template <class T>
void PriorityQueue<T>::doubleCap()
{
	if (capacity > 0)
		capacity = capacity * 2;
	else
		capacity = 2;
	T* temp = new T[capacity];
	for (int i = 0; i < capacity; i++)
		temp[i] = PQarray[i];
	if (PQarray != NULL)
		delete[] PQarray;
	PQarray = temp;
}

#endif
