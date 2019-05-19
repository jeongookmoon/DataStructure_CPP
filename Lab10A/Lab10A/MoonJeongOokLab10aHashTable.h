#ifndef MOONJEONGOOKLAB10AHASHTABLE_H
#define MOONJEONGOOKLAB10AHASHTABLE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

template <class Val, class Key, int Cap>
class HashTable
{
private:
	struct HashNode
	{
		Key key;
		Val value;
		void operator=(const Val& val) { value = val; }// this is for find
		bool operator==(const HashNode& rv_node) const { return key == rv_node.key; } // this is for find	
	};
	list<HashNode> data[Cap];
	Val dummy;
	int size;
	int(*hashFunc)(const Key&); // pointer to Key's hashfunction
	int getWrappedIndexHash(const Key&) const; // returns the Hash index
	
public:
	HashTable(int(*)(const Key&));
	
	Val operator[](const Key&) const;
	Val& operator[](const Key&);
	int Size() const;
	int Capacity() const;
	bool ContainsKey(const Key&) const;
	bool DeleteKey(const Key&);
	void Clear();
	vector<Key> Keys() const;
};

template <class Val, class Key, int Cap>
int HashTable<Val, Key, Cap>::Size() const
{
	return size;
}
template <class Val, class Key, int Cap>
int HashTable<Val, Key, Cap>::Capacity() const
{
	return .8 * Cap;
}

template<class Val, class Key, int Cap>
int HashTable<Val, Key, Cap>::getWrappedIndexHash(const Key &rv_key) const
{
	int hashkey = hashFunc(rv_key) % Cap;
	if (hashkey > 0)
		return hashkey;
	else
		return -hashkey;
}

template <class Val, class Key, int Cap>
HashTable<Val, Key, Cap>::HashTable(int(*hashF)(const Key&))
{
	hashFunc = hashF;
	size = 0;
}

template <class Val, class Key, int Cap>
Val& HashTable<Val, Key, Cap>::operator[](const Key &rv_key) // setter
{
	//get "wrapped index", 0 to cap - 1
	int hashkey = getWrappedIndexHash(rv_key);

	typename list<HashNode>::iterator pointer; // pointer* = new Node[];
	HashNode temp;
	temp.key = rv_key; // key is parameter 

	pointer = find(data[hashkey].begin(), data[hashkey].end(), temp);
	// finding where it is.

	if (pointer == data[hashkey].end()) // no matching key 
	{
		size++;
		data[hashkey].push_back(temp); // save key at index, this takes care of COLLISION by adding new node to end of the list.
		return data[hashkey].back().value; // return unset value at index
	}
	else return pointer->value; // return value when key is found and matches.
}

template <class Val, class Key, int Cap>
Val HashTable<Val, Key, Cap>::operator[](const Key &rv_key) const //getter
{
	int hashkey = getWrappedIndexHash(rv_key); // get "wrapped index", 0 to cap - 1

	typename list<HashNode>::iterator pointer; // pointer* = new Node[];
	HashNode temp;
	temp.key = rv_key; // key is parameter 
	
	pointer = find(data[hashkey].begin(), data[hashkey].end(), temp);

	//finding where it is

	if (pointer == data[hashkey].end()) // return dummy, if the key is not found
		return dummy;
	else
		return pointer->value; // if inUse and key matches, return value
}

template <class Val, class Key, int Cap>
bool HashTable<Val, Key, Cap>::ContainsKey(const Key &rv_key) const
{
	int hashkey = getWrappedIndexHash(rv_key); // get"wrapped index"
	typename list<HashNode>::const_iterator pointer;
	HashNode temp;
	temp.key = rv_key;
	pointer = data[hashkey].begin();
	pointer = find(data[hashkey].begin(), data[hashkey].end(), temp);
	if (pointer == data[hashkey].end()) // there's no matching key
		return false;
	else
		return true;
		
}

template <class Val, class Key, int Cap>
bool HashTable<Val, Key, Cap>::DeleteKey(const Key &rv_key)
{
	int hashkey = getWrappedIndexHash(rv_key); // get"wrapped index"
	typename list<HashNode>::iterator pointer;
	HashNode temp;
	temp.key = rv_key;
	pointer = find(data[hashkey].begin(), data[hashkey].end(), temp);
	if (pointer == data[hashkey].end()) // there's no matching key
		return false;
	else // when there's a matching key
	{
		data[hashkey].erase(pointer); // erase that pointer
		size--; // and decrease size
		return true;
	}
}

template <class Val, class Key, int Cap>
vector<Key> HashTable<Val, Key, Cap>::Keys() const
{
	vector<Key> keys;
	typename list<HashNode>::const_iterator pointer;

	for (int i = 0; i < Cap; i++)
	{
		for (pointer = data[i].begin(); pointer != data[i].end(); pointer++)
		{
			keys.push_back(pointer->key);
		}
	}

	return keys;
}

template<class Val, class Key, int Cap>
void HashTable<Val, Key, Cap>::Clear()
{
	size = 0;
	for (int i = 0; i < Cap; i++)
		data[i].clear();
}


#endif