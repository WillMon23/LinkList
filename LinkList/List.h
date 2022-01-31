#pragma once
#include "Iterator.h"
#include <iostream>


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
	bool remove(const T& value);
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
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* currentNode = m_head;

	while (currentNode != m_tail)
	{
		
	}
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	m_head->previous = nullptr;
	Iterator<T> temp = Iterator<T>(m_head);
	return temp;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	m_tail->previous = nullptr;
	Iterator<T> temp = Iterator<T>(m_tail);
	return temp;
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	Iterator<T> temp = begin();

	while (temp != end())
	{
		if (*temp == object)
			return true;
		temp++;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* temp = new Node<T>(value);

	if (m_head->previous != nullptr)
		m_head->previous = temp;

	begin();
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	m_tail->next = new Node<T>(value);
	end();
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Node<T>* currentNode = m_head;
	Node<T>* insertedNode = new Node<T>(value);
	
	for (int i = 0; i < index; i++)
	{
		if (currentNode->next != nullptr)
			currentNode = currentNode->next;
		else
			return false;
	}


	insertedNode->next = currentNode;
	insertedNode->previous = currentNode->previous;
	currentNode->previous->next = insertedNode;

	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* currentNode = m_head;

	while (currentNode->data != value)
	{
		if (currentNode->next != nullptr)
			currentNode = currentNode->next;
		else
			return false;
	}


	currentNode->previous->next = currentNode->next;
	currentNode->next->previous = currentNode->previous;

	delete currentNode;

	return false;
}

template<typename T>
inline void List<T>::print() const
{
	Node<T>* currentNode = m_head;
	while (currentNode->next != nullptr)
	{
		std::cout << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if(begin() == nullptr)
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
