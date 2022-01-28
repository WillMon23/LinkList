#pragma once
#include "Iterator.h"


template <typename T>
class List {
public:
	List() {};
	List(const List<T>&);
	~List() {};

public:
	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;
	bool contains(const T object) const;
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value, int index);
	void print() const;
	void initialize();
	bool isEmpty()const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const { return m_nodeCount; };
	List<T>& operator=(const List<T>& otherList) const;
	void sort();

private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodeCount;

};

template<typename T>
inline List<T>::List(const List<T>&)
{
}

template<typename T>
inline void List<T>::destroy()
{

}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>();
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value, int index)
{
	return false;
}

template<typename T>
inline void List<T>::print() const
{
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& otherList) const
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}
