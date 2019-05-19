#ifndef MOONJEONGOOKLAB07ASTACK_H
#define MOONJEONGOOKLAB07ASTACK_H

/// I referenced lecture note (Dr. Burns' code) to write this h file.

template <class T>
class Stack
{
private:
	
	static const int cap_initial = 10;
	int cap;
	T* values;
	int size;
	T dummy;

	void setCapacity(int newCap);


public:
	Stack (int = cap_initial);
	Stack (const Stack<T>& arr);
	~Stack();

	Stack<T>& operator=(const Stack<T>& arr);
	
	T operator[](unsigned int index) const; // getter for array, not stack
	
	void doubleCapacity();
	void halveCapacity();
	unsigned int getCapacity() const { return cap; }

	bool isEmpty() const { return size == 0; }
	unsigned int Size() const { return size; }
	void Clear() { size = 0; }
	void Push(const T&);
	bool Peek(T&);
	bool Pop(T&);
};

template <class T>
Stack<T>::Stack( int cap_initial )
{
	cap = cap_initial;
	size = 0;
	values = new T[cap];
}

template <class T>
Stack<T>::Stack(const Stack<T>& arr) // copy constructor
{
	cap = arr.cap;
	size = arr.size;
	values = new T[cap];
	for (unsigned int i = 0; i < cap; i++)
		values[i] = arr.values[i];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] values;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& arr)
{
	if (this == &arr)
		return *this;
	delete[] values;
	cap = arr.cap;
	size = arr.size;
	values = new T[cap];
	for (unsigned int i = 0; i < cap; i++)
		values[i] = arr.values[i];
	return *this;
}

template <class T>
void Stack<T>::setCapacity(int newCap)
{
	T* temp = new T[newCap];
	unsigned int max;
	if (newCap <= cap)
		max = newCap;
	else
		max = cap;
	for (unsigned int i = 0; i < max; i++)
		temp[i] = values[i];
	delete[] values;
	
	values = temp;
	cap = newCap;
	
	if (size < cap)
		size = cap;
}

template <class T>
T Stack<T>::operator[](unsigned int index) const
{
	if (index >= cap)
		return dummy;
	return values[index];
}

template <class T>
void Stack<T>::doubleCapacity()
{
	if (cap > 0)
		cap = cap * 2;
	else
		cap = cap_initial;
	T* temp = new T[cap];
	for (unsigned int i = 0; i < cap; i++)
		temp[i] = values[i];
	if (values)
		delete[] values;
	values = temp;
}

template <class T>
void Stack<T>::halveCapacity()
{
	if (cap > 0)
		cap = cap / 2;
	else
		cap = cap_initial;
	T* temp = new T[cap];
	for (unsigned int i = 0; i < cap; i++)
		temp[i] = values[i];
	if (values)
		delete[] values;
	values = temp;
}

template <class T>
void Stack<T>::Push(const T& object)
{
	if (++size > cap)
	{
		doubleCapacity();
	}
	values[size - 1] = object;
}

template <class T>
bool Stack<T>::Peek(T& object)
{
	if (size == 0)
		return false;
	object = values[size - 1];
	return true;
}

template <class T>
bool Stack<T>::Pop(T& object)
{
	if (size == 0)
		return false;
	object = values[--size];
	if (size > 2 && size < cap / 4)
		halveCapacity();
	return true;
}


#endif
