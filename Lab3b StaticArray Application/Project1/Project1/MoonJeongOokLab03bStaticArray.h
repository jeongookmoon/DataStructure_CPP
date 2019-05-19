#ifndef MOONJEONGOOKLAB03BSTATICARRAY_H
#define MOONJEONGOOKLAB03BSTATICARRAY_H

#include <vector>
using namespace std;

// DECLARATION
template <class T, unsigned int CAPACITY>
class StaticArray
{
public:
	static T dummy;
private:
	T values[CAPACITY];
	bool inUse[CAPACITY];
	unsigned int size;
public:
	StaticArray();
	T operator[](unsigned int index)const;
	T& operator[](unsigned int index);
	unsigned int Size()const { return size; }
	unsigned int Capacity()const { return CAPACITY; }
	bool ContainsKey(unsigned int index)const;
	void DeleteKey(unsigned int index);
	vector<unsigned int> Keys()const;
	void Clear();
};

// IMPLEMENTATION
template <class T, unsigned int CAPACITY>
T StaticArray<T, CAPACITY>::dummy = T();

template <class T, unsigned int CAPACITY>
StaticArray<T, CAPACITY>::StaticArray()
	:size(0)
{
	for (unsigned int i = 0; i < CAPACITY; ++i)
	{
		values[i] = T();
		inUse[i] = false;
	}
}

/*template <class T, unsigned int CAPACITY>
T 	StaticArray<T, CAPACITY>::operator[](unsigned int index)const
{
	if (index >= CAPACITY || index <0)
		return dummy;
	if (inUse[index])
		return values[index];
	//return dummy;
}

template <class T, unsigned int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](unsigned int index)
{
	if (index >= CAPACITY || index < 0)
		return dummy;
	if (!inUse[index]) size++;
	inUse[index] = true;
	return values[index];
}
*/
template<class T, unsigned int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](unsigned int index)
{
	if (index < 0) return dummy;
	if (index >= CAPACITY) return dummy;
	if (!inUse[index]) size++;
	inUse[index] = true;

	return values [index];
}

template<class T, unsigned int CAPACITY>
T StaticArray<T, CAPACITY>::operator[](unsigned int index) const
{
	if (index < 0) return dummy;
	if (index >= CAPACITY) return dummy;

	return values[index];
}

template <class T, unsigned int CAPACITY>
bool StaticArray<T, CAPACITY>::ContainsKey(unsigned int index)const
{
	if (index < 0 || index >= CAPACITY) 
		return false;
		
	return inUse[index];
}


template <class T, unsigned int CAPACITY>
void StaticArray<T, CAPACITY>::DeleteKey(unsigned int index)
{
	if (index < CAPACITY)
		inUse[index] = false;
}

template <class T, unsigned int CAPACITY>
vector<unsigned int> StaticArray<T, CAPACITY>::Keys()const
{
	vector<unsigned int> a;
	for (unsigned int i = 0; i < CAPACITY; ++i)
		if (inUse[i])
			a.push_back(i);
	return a;
}

template <class T, unsigned int CAPACITY>
void StaticArray<T, CAPACITY>::Clear()
{
	for (unsigned int i = 0; i < CAPACITY; ++i)
		inUse[i] = false;
}

template <class T, unsigned int M>
ostream & operator<<(ostream & os, const StaticArray<T, M> object)
{
	int i = 0, s = object.Size();
	vector<unsigned int> inUse = object.Keys();
	if (s != inUse.size())
		throw ("Error in operator<<");
	while (i < s)
	{
		os << inUse[i] << ":" <<
			object[inUse[i]];
		i++;
		if (i < s)
			os << "\n";
	}
	return os;
}
#endif