#ifndef MOONJEONGOOKLAB06ALINKEDARRAY_H
#define MOONJEONGOOKLAB06ALINKEDARRAY_H

/// I referenced Professor Schick's LinkedArray.h file to write this h file.
#include <vector>
using namespace std;


template <class T>
class LinkedArray
{

public:
	template <class A>
	struct Node // creating struct Node, creating value, bool variable, pointer to next, and key
	{
		A value; // value
		bool inUse; // bool variable to show whether the index is empty or not
		Node* next; // node pointing next
		int key; // works like an index
		Node()
		{
			value = A();
			inUse = false;
			key = -1;
			next = NULL;
		}
	};

	LinkedArray();
	LinkedArray(const LinkedArray<T> & copy);
	virtual ~LinkedArray();
	LinkedArray<T>& operator=(const LinkedArray<T> &copy);


	T operator[] (int index) const; // getter, reading what's in index
	T& operator[] (int index); // setter, setting the value of the index
	int Size() const { return size; } // shows how many inUse elements there are
	int Capacity() const { return cap; } // shows how many values in array
	bool ContainsKey(int index) const; // true/false depending on if the key is found or not
	void DeleteKey(int index); // makes the index's inUse to not inUse.
	vector<int> Keys() const;
	void Clear();

private: // creating members of the class, start and end node pointers, cap and size, and dummy.
	Node<T>* start; // node pointing start
	Node<T>* end; // node pointing start
	int cap; // one larger than largest in-use or previously used key.
	int size; // number of inUse nodes
	T dummy; // dummy

	void Delete(); // this is for destructor
	void Copy(const LinkedArray<T> &copy);
};

template <class T>
LinkedArray<T>::LinkedArray()
{
	start = end = NULL;
	size = cap = 0;
}

template <class T>
LinkedArray<T>::~LinkedArray()
{
	Delete();
}


template <class T>
LinkedArray<T> & LinkedArray<T>::operator=(const LinkedArray<T> & object)
{
	if (this != &object)
	{
		Delete();
		Copy(object);
	}
	return *this;
}

template <class T>
LinkedArray<T>::LinkedArray(const LinkedArray<T> &object)
{
	start = end = NULL;
	size = cap = 0;
	Copy(object);
}


template <class T>
T LinkedArray<T>::operator[] (int index) const // accessor, getter, just for reading the value of the index
{
	if (index < 0 || index > cap) // if index is not valid, then return dummy
		return dummy;
	Node<T> *const*travelP = &start; // creating new pointer node to point start
	while ((*travelP) != NULL && (*travelP)->key < index) // traveling using p until p->key goes before index value.
		travelP = &((*travelP)->next);
	if ((*travelP) == NULL) // if p is Null, then return dummy
		return dummy;
	else if ((*travelP)->key > index) // if p->key is greater than our index, than return dummy
		return dummy;
	else // if p->key is same to index, then we return the value of that index
		return (*travelP)->value;
}


template <class T>
T& LinkedArray<T>::operator[] (int index) // mutator, setter, to write the value in the index
{
	if (index < 0) // if index is less than 0, return dummy
		return dummy;

	if (index >= cap) // if our index is equal or greater than capacity
	{
		if (end == NULL) // in case, end is null
		{
			start = end = new Node<T>; // initiating two nodes start and end and setting them equal to each other 
		}
		else
		{
			end->next = new Node<T>; // initiating end->next node and setting end equal to end->next so end move to next
			end = end->next;
		}
		end->key = index; // setting new end's key equal to index
		end->inUse = true;  // switching new end to be in use
		size++; // increase a size (how many are in use)
		cap = index + 1; // also increase capacity by (index + 1) (total elements + 1)
		return end->value; // finally return the value at the end.
	}

	Node<T> **p = &start; // initiating pointer p and making it equal to address of the start.
	while ((*p) != NULL && (*p)->key < index)
		p = &((*p)->next); // moving (*p)->next until (p*)->key becomes less than index and changing it to p.
	Node<T> *q = NULL;
	if ((*p)->key > index) // if p*-> key is larger than index
	{
		q = new Node<T>;
		q->key = index;
		q->next = *p;
		*p = q;  // so p takes previous position than q.
	}
	else
	{
		q = *p;
	}
	if (q->inUse == false)
	{
		size++;
		q->inUse = true; // making q to be in use and increase size
	}
	return q->value;
}



template <class T>
bool LinkedArray<T>::ContainsKey(int index) const // checking if the key is in use or not.
{
	if (index < 0 || index >= cap)
	{
		return false;
	}
	Node<T> const *p = start; // node pointer p to traverse
	while (p != NULL && p->key < index) // as long as p is not NULL and located before index, p keeps travesing
		p = p->next;
	if (p != NULL && p->key == index && p->inUse == true) //if p key is found and that's in use then return true.
		return true;
	return false;
}


template <class T>
void LinkedArray<T>::DeleteKey(int index)
{
	if (index >= 0 && index < cap)
	{
		Node<T> *p = start;
		while (p != NULL && p->key < index) // finding the index
			p = p->next;
		if (p != NULL && p->key == index) // if found, then delete
		{
			if (p->inUse == true) // if true inUse is found, lessen the size and make it false.
				size--;
			p->inUse = false;
		}
	}
}

template <class T>
vector<int> LinkedArray<T>::Keys() const // this is to extract only inUse elements into vector whatsinside then to return whatsinside
{
	vector<int> whatsinside;
	Node<T> const *movingP = start; // node pointer movingP will move from where start is at to where the end is (null is)
	while (movingP != NULL)
	{
		if (movingP->inUse == true)
			whatsinside.push_back(movingP->key);
		movingP = movingP->next;
	}
	return whatsinside; // then return all values in vector whatsinside
}

template <class T> // as pointer p traverses until the end(NULL) it makes every inUse false and at the end makes the size 0.
void LinkedArray<T>::Clear()
{
	Node<T> *p = start;
	while (p != NULL)
	{
		p->inUse = false;
		p = p->next;
	}
	size = 0;
}


template <class T>
void LinkedArray<T>::Delete()
{
	Node<T> *movingPtr = start;
	while (start != NULL)
	{
		start = start->next;
		delete movingPtr;
		movingPtr = start;
	}
	start = end = NULL;
	cap = size = 0;
}

template <class T>
void LinkedArray<T>::Copy(const LinkedArray<T> & object)
{
	Node<T> * copyP = object.start;  // creating copy pointer and setting that equals to copy.start 
	Node<T> * insertP = NULL;		// creating insert pointer and setting it to null
	while (copyP != NULL) // while copy pointer isn't null
	{
		if (copyP == object.start) // then create new node called start and setting insert pointer equal to start node.
		{
			start = new Node<T>;
			insertP = start;
		}
		else // now initiate insert pointer's next node and setting that equal to insert pointer (so insert pointer traveling to next one)
		{
			insertP->next = new Node<T>;
			insertP = insertP->next;
		}
		insertP->value = copyP->value; // now copying copy pointer's value into insert's
		insertP->inUse = copyP->inUse; // copying copy pointer's inUse into insert's
		insertP->key = copyP->key; // copying copy pointer's key into insert's 
		if (copyP == object.end) // when copy pointer hits the end
			end = insertP; // copy pointer's end becomes insert pointer	
		copyP = copyP->next; // copy pointer's next becomes copy pointer itself
	}
	size = object.size;
	cap = object.cap;
}


template <class T>
ostream & operator<<(ostream& osout, const LinkedArray<T> & object) // cout elements stored in vector whatsinside
{
	vector<int> whatsinside = object.Keys();
	int size = whatsinside.size();
	for (int i = 0; i < size; i++)
	{
		osout << "Keys : " << whatsinside[i] << ", Value : " << object[whatsinside[i]];
		if (i < size - 1)
			osout << "\n";
	}

	return osout;
}


#endif
