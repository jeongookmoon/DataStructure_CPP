#ifndef MOONJEONGOOKLAB04ADYNAMICARRAY_H
#define MOONJEONGOOKLAB04ADYNAMICARRAY_H

#include <vector>
using namespace std;

template <class T>
class DynamicArray
{

private:
	static const int INIT_CAP = 100;
	unsigned int cap;
	T* values;
	bool* inUse;
	T dummy;
	unsigned int size;

public:

	DynamicArray(int = INIT_CAP);
	DynamicArray(const DynamicArray<T> &);
	virtual ~DynamicArray();
	DynamicArray<T> & operator=(const DynamicArray<T> &);
	T operator[](unsigned int index)const;
	T& operator[](unsigned int index);
	unsigned int Size()const;
	unsigned int Capacity()const;
	bool ContainsKey(unsigned int index)const;
	void DeleteKey(unsigned int index);
	vector<unsigned int> Keys()const;
	void Clear();

private:
	void Copy(const DynamicArray<T> &);
	void Delete();
	void SetCapacity(unsigned int INIT_CAP);
};


template <class T>
DynamicArray<T>::DynamicArray(int init_cap)
{
	cap = init_cap;
	values = new T[cap];
	inUse = new bool[cap];
	size = 0;

	for (unsigned int i = 0; i < cap; i++)
		inUse[i] = false;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> & a)
	:values(NULL), inUse(NULL)
{
	Copy(a);
}
template <class T>
DynamicArray<T>::	~DynamicArray()
{
	Delete();
}

template <class T>
DynamicArray<T> & DynamicArray<T>::operator=(const DynamicArray<T> & a)
{
	if (this != &a)
	{
		Delete();
		Copy(a);
	}
	return *this;
}

template <class T>
T DynamicArray<T>::operator[](unsigned int index)const
{
	if (index >= cap)
		return dummy;
	return values[index];
}

template <class T>
T& DynamicArray<T>::operator[](unsigned int index)
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
unsigned int DynamicArray<T>::Size()const
{
	return size;
}

template <class T>
unsigned int DynamicArray<T>::Capacity()const
{
	return cap;
}

template <class T>
bool DynamicArray<T>::ContainsKey(unsigned int index)const
{
	if (index < cap)
		return inUse[index];
	return false;
}

template <class T>
void DynamicArray<T>::DeleteKey(unsigned int index)
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
vector<unsigned int> DynamicArray<T>::Keys()const
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
void DynamicArray<T>::Clear()
{
	for (unsigned int i = 0; i < cap; ++i)
		inUse[i] = false;
}

template <class T>
void DynamicArray<T>::Copy(const DynamicArray<T> & object)
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
void DynamicArray<T>::Delete()
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
void DynamicArray<T>::SetCapacity(unsigned int newCap = 10)
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
ostream & operator<<(ostream & outs, const DynamicArray<T> & object)
{
	vector<unsigned int> a = object.Keys();
	for (unsigned int i = 0; i < a.size(); ++i)
	{
		cout << "<< " << a[i] << ": " <<
			object[a[i]] << " >>";
		if (i < a.size() - 1)
			cout << ", ";
	}
	outs << "\n";
	return outs;
}



#endif