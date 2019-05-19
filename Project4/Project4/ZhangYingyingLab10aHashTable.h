// ZhangYingyingLab10aHashTable.h
// Yingying Zhang
// on 11/01/2015
// Editor(s) used: X Code
// Compiler(s) used: X Code
// The Hash Table Header File

#ifndef HashTable_h
#define HashTable_h

#include <vector>
#include <list>
using namespace std;

template <class T, class U, int CAPACITY>
class HashTable
{
private:
  struct Node
  {
    T value;
    U key;
    void operator=(const T& v){ value = v; }
    bool operator==(const Node& n) const { return key == n.key; }
  };
  
  list<Node> data[CAPACITY];
  int(*hashCode)(const U&);
  int getWrappedIndex(const U&) const;
  int sz;
  
public:
  T dummy;
  
public:
  HashTable(int(*)(const U&));
  T& operator[](const U&);
  T operator[](const U&) const;
  int size() const;
  int capacity() const;
  bool containsKey(const U&) const;
  void deleteKey(const U&);
  vector<U> keys() const;
  void clear();
};

// constructor
template <class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::HashTable(int(*x)(const U&))
{
  sz = 0;
  hashCode = x;
}

template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::getWrappedIndex(const U& key) const
{
  int wi = hashCode(key) % CAPACITY;
  if (wi < 0)
    wi += CAPACITY;
  return wi;
}

// setter
template <class T, class U, int CAPACITY>
T& HashTable<T, U, CAPACITY>::operator[](const U& key)
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end())
  {
    sz++;
    data[wi].push_back(temp);
    return data[wi].back().value;
  }
  else
    return it->value;
}

// getter
template <class T, class U, int CAPACITY>
T HashTable<T, U, CAPACITY>::operator[](const U& key) const
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end())
    return dummy;
  else
    return it->value;
}

// capacity function
template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::capacity() const
{
  return 0.8 * CAPACITY;
}

// size function
template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::size() const
{
  return sz;
}

// containsKey function
template <class T, class U, int CAPACITY>
bool HashTable<T, U, CAPACITY>::containsKey(const U& key) const
{
  int wi = getWrappedIndex(key);
  typename list<Node>::const_iterator it;
  Node temp; temp.key = key;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end())
    return false;
  else
    return true;
}

// deleteKey function
template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::deleteKey(const U& key)
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it != data[wi].end())
  {
    sz--;
    data[wi].erase(it);
  }
}

// keys function
template <class T, class U, int CAPACITY>
vector<U> HashTable<T, U, CAPACITY>::keys() const
{
  vector<U> result;
  typename list<Node>::const_iterator it;
  for (int wi = 0; wi < CAPACITY; wi++)
    for (it = data[wi].begin(); it != data[wi].end(); it++)
      result.push_back(it->key);
  return result;
}

// clear function
template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::clear()
{
  for (int i = 0; i < CAPACITY; i++)
    data[i].clear();
}

#endif