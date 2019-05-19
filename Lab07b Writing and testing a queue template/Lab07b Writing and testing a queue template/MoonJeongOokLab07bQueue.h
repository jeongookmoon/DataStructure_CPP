#ifndef MOONJEONGOOKLAB07BQUEUE_H
#define MOONJEONGOOKLAB07BQUEUE_H

/// I referenced Professor Schick's ListQueue.h file to write this h file.

template <class T>
struct Node
{
	T value;
	Node* next;

	Node()
	{
		value = T();
		next = NULL;
	}

};

template <class T>
class Queue
{

private:
	Node<T> front;
	Node<T>* back;
	int size;

public:
	Queue();
	Queue(const Queue<T>& object);
	Queue<T> & operator=(const Queue<T> &object);
	~Queue();

	bool isEmpty() const;
	void enQueue(const T& object);
	T peek() const;
	void deQueue();
	unsigned int Size();
};

template <class T>
Queue<T>::Queue()
{
	front;
	back = &front;
	size = 0;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return (size == 0);
}

template <class T>
Queue<T>::Queue(const Queue<T>& object)
{
	front;
	back = &front;
	size = 0;
	Node<T> * temp = object.front.next;
	while (temp)
	{
		enQueue(temp->value);
		temp = temp->next;
	}
}

template <class T>
Queue<T> & Queue<T>::operator=(const Queue<T> &object)
{
	if (this != &object)
	{
		while (!isEmpty())
			deQueue();
		Node<T> *temp = object.front.next;
		while (temp)
		{
			enQueue(temp->value);
			temp = temp->next;
		}
	}
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	while (!isEmpty())
	{
		deQueue();
	}
}
template <class T>
void Queue<T>::enQueue(const T& object)
{
	Node<T>* temp = new Node<T>();
	temp->value = object;
	back->next = temp;
	back = temp;
	size++;
}

template <class T>
T Queue<T>::peek() const
{
	if (&front != back)
		return front.next->value;
	return T();
}

template <class T>
void Queue<T>::deQueue()
{
	if (&front != back)
	{
		Node<T> *temp = front.next;
		front.next = front.next->next;
		if (temp == back)
			back = &front;
		size--;
		delete temp;
	}
}

template<class T>
unsigned int Queue<T>::Size()
{
	return size;
}


#endif
