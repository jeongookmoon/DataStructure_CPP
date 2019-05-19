#ifndef MOONJEONGOOKLAB09BASSOCIATIVEARRAY
#define MOONJEONGOOKLAB09BASSOCIATIVEARRAY

#include <vector>
using namespace std;

template <class Val, class Key>
class Array
{
private:
	struct Node
	{
		Val value;
		Key key;
		bool inUse;
		Node* next;

		Node()
		{
			value = Val();
			key = Key();
			inUse = false;
			next = NULL;
		}
	};

	Node *begin;
	int size;
	int cap;
	Val dummy;

public:
	Array();
	Array(const Array<Val, Key> & array_copy);
	Array<Val, Key> &operator=(const Array<Val, Key> & array_copy);
	~Array();

	Val operator[](const Key& key_copy) const;
	Val& operator[](const Key& key_copy);
	unsigned int Size() const;
	unsigned int Capacity() const;
	vector<Key> Keys() const;
	bool ContainsKey(const Key& key_copy) const;
	bool DeleteKey(const Key& key_copy);
	void Clear();
};
template <class Val, class Key>
unsigned int Array<Val, Key>::Size() const
{
	return size;
}

template <class Val, class Key>
unsigned int Array<Val, Key>::Capacity() const
{
	return cap;
}

template <class Val, class Key>
Array<Val, Key>::Array()
{
	begin = NULL;
	size = 0;
	cap = 0;
}

template <class Val, class Key>
Array<Val, Key>::Array(const Array<Val, Key> & array_copy)
{
	begin = NULL;
	size = 0;
	cap = 0;

	size = array_copy.size;
	cap = array_copy.cap;
	const Node* copyP = array_copy.begin;
	Node* insertP = begin;
	while (copyP != NULL)
	{
		if (begin == NULL)
		{
			begin = new Node;
			insertP = begin;
		}
		else
		{
			insertP->next = new Node;
			insertP = insertP->next;
		}
		insertP->key = copyP->key;
		insertP->value = copyP->value;
		insertP->inUse = copyP->inUse;
		copyP = copyP->next;
	}
}

template <class Val, class Key>
Array<Val, Key>::~Array()
{
	while (begin)
	{
		Node* p = begin;
		begin = begin->next;
		delete p;
	}
	begin = NULL;
	size = cap = 0;
}

template < class Val, class Key >
Array<Val, Key> &Array < Val, Key > ::operator=(const Array<Val, Key> & array_copy)
{
	if (this != &array_copy)
	{
		while (begin != NULL)
		{
			Node* p = begin;
			begin = begin->next;
			delete p;
		}
		begin = NULL;
		size = cap = 0;

		size = array_copy.size;
		cap = array_copy.cap;
		Node* copyP = array_copy.begin;
		Node* insertP = begin;
		while (copyP != NULL)
		{
			if (begin == NULL)
			{
				begin = new Node;
				insertP = begin;
			}
			else
			{
				insertP->next = new Node;
				insertP = insertP->next;
			}
			insertP->key = copyP->key;
			insertP->value = copyP->value;
			insertP->inUse = copyP->inUse;
			copyP = copyP->next;
		}
	}
	return *this;
}

template <class Val, class Key>
Val Array<Val, Key>::operator[](const Key& key_copy) const
{
	Node* movingP = begin;
	while (movingP != NULL)
	{
		if (key_copy == movingP->key )
			if (movingP->inUse == true)
				return movingP->value;
		movingP = movingP->next;
	}
	return dummy;
}

template <class Val, class Key>
Val& Array<Val, Key>::operator[](const Key& key_copy)
{
	Node *movingP = begin;
	while (movingP != NULL) // finding the key
	{
		if (movingP->inUse == true)
			if (movingP->key == key_copy)
				return movingP->value;
		movingP = movingP->next;
	}
	// if not found
	movingP = begin;
	while (movingP != NULL)
	{
		if (movingP->inUse == false) // will use not-in-use spot
		{
			movingP->inUse = true;
			movingP->key = key_copy;
			size++;
			return movingP->value;
		}
		movingP = movingP->next;
	}
	// in last case, attach new moving P next to begin and let begin be at new beginning spot. also return begin's value.
	movingP = new Node;
	movingP->inUse = true;
	movingP->key = key_copy;
	movingP->next = begin;
	begin = movingP;
	size++;
	cap++;
	return movingP->value;

}

template <class Val, class Key>
bool Array<Val, Key>::ContainsKey(const Key & key_copy) const
{
	Node* movingP = begin;
	while (movingP != NULL)
	{
		if (movingP->inUse == true)
			if (movingP->key == key_copy)
				return true;
		movingP = movingP->next;
	}
	return false;
}

template <class Val, class Key>
bool Array<Val, Key>::DeleteKey(const Key & key_copy)
{
	Node* movingP = begin;
	while (movingP != NULL)
	{
		if (movingP->inUse == true)
			if (movingP->key == key_copy)
			{
				movingP->inUse = false;
				size--;
				return true;
			}
		movingP = movingP->next;
	}
	return false;
}

template <class Val, class Key>
void Array<Val, Key>::Clear()
{
	Node* movingP = begin;
	while (movingP != NULL)
	{
		movingP->inUse = false;
		movingP = movingP->next;
	}
	size = 0;
}

template <class Val, class Key>
vector<Key> Array<Val, Key>::Keys() const
{
	vector<Key> inside;
	Node* movingP = begin;
	while (movingP != NULL)
	{
		if (movingP->inUse == true)
			inside.push_back(movingP->key);
		movingP = movingP->next;
	}
	return inside;

}
#endif

