#ifndef MOONJEONGOOKLAB13ASORTABLEStaticArray_H
#define MOONJEONGOOKLAB13ASORTABLEStaticArray_H

#include <vector>
#include <algorithm>
using namespace std;


template <class T, unsigned int CAPACITY>
class SortableStaticArray
{
private:
	T values[CAPACITY];
	bool inUse[CAPACITY];
	unsigned int size;
	T dummy;

public:
	SortableStaticArray();
	T operator[](unsigned int index)const;
	T& operator[](unsigned int index);
	unsigned int Size()const { return size; }
	unsigned int Capacity()const { return CAPACITY; }
	bool ContainsKey(unsigned int index)const;
	void DeleteKey(unsigned int index);
	vector<unsigned int> Keys()const;
	void Clear();
	void Sort();
	bool operator<(const T& rv_Array)const;
};



template <class T, unsigned int CAPACITY>
SortableStaticArray<T, CAPACITY>::SortableStaticArray()
{
	size = 0;
	for (unsigned int i = 0; i < CAPACITY; ++i)
	{
		values[i] = T();
		inUse[i] = false;
	}
}

template <class T, unsigned int CAPACITY>
T SortableStaticArray<T, CAPACITY>::operator[](unsigned int index)const
{
	if (index >= CAPACITY)
		return dummy;
	if (inUse[index])
		return values[index];
	return dummy;
}

template <class T, unsigned int CAPACITY>
T& SortableStaticArray<T, CAPACITY>::operator[](unsigned int index)
{
	if (index >= CAPACITY)
		return dummy;
	if (!inUse[index]) size++;
	inUse[index] = true;
	return values[index];
}

template <class T, unsigned int CAPACITY>
bool SortableStaticArray<T, CAPACITY>::ContainsKey(unsigned int index)const
{
	if (index < CAPACITY)
		return inUse[index];
	return false;
}

template <class T, unsigned int CAPACITY>
void SortableStaticArray<T, CAPACITY>::DeleteKey(unsigned int index)
{
	if (index < CAPACITY)
		inUse[index] = false;
}

template <class T, unsigned int CAPACITY>
vector<unsigned int> SortableStaticArray<T, CAPACITY>::Keys()const
{
	vector<unsigned int> a;
	for (unsigned int i = 0; i < CAPACITY; ++i)
		if (inUse[i])
			a.push_back(i);
	return a;
}

template <class T, unsigned int CAPACITY>
void SortableStaticArray<T, CAPACITY>::Clear()
{
	for (unsigned int i = 0; i < CAPACITY; ++i)
		inUse[i] = false;
}
template <class T, unsigned int CAPACITY>
bool SortableStaticArray<T, CAPACITY>::operator<(const T& rv_Array)const
{
	if (this.values < rv_Array)
		return true;
	return false;
}
template <class T, unsigned int CAPACITY>
void SortableStaticArray<T, CAPACITY>::Sort()
{
	// Insertion sort
	for (unsigned int i = 0; i < size - 1; i++) // i is to track end of sorted array
	{
		for (int j = i + 1; j > 0; j--) // j is to track position of inserting value;
		{
			if (values[j - 1] < values[j])
				break;
			swap(values[j], values[j - 1]);
		}
	}
}

#endif