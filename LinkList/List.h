#pragma once
#include "Iterator.h"
#include <iostream>


template <typename T>
class List {
public:
	List() { initialize(); };
	List(const List<T>& other);
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
	const List<T>& operator=(const List<T>& otherList);
	void sort();

private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodeCount;

};

template<typename T>
inline List<T>::List(const List<T>& other)
{
	m_head = other.m_head;
	m_tail = other.m_tail;
	m_nodeCount = other.m_nodeCount;
}

template<typename T>
inline void List<T>::destroy()
{
	delete m_head, m_tail;
	initialize();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
		return Iterator<T>(m_head);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
		return Iterator<T>(m_tail->next);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	Iterator<T> temp =  begin();

	while (temp != end())
	{
		if (*temp == object)
			return true;
		++temp;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Iterator<T> temp = begin();
	Node<T>* pushInsert = new Node<T>(value);
	if (isEmpty())
	{
		m_head = pushInsert;
		m_tail = pushInsert;
	}
	else
	{
		m_head->previous = pushInsert;
		pushInsert->next = m_head;
		m_head = pushInsert;
	}

	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* pushInsert = new Node<T>(value);
	if (isEmpty())
	{
		m_head = pushInsert;
		m_tail = pushInsert;
	}
	else
	{
		m_tail->next = pushInsert;
		pushInsert->previous = m_tail;
		m_tail = pushInsert;
	}

	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Node<T>* currentNode = m_head;
	Node<T>* insertedNode = new Node<T>(value);
	if (isEmpty())
	{
		m_head = insertedNode;
		m_tail = insertedNode;
		return false;
	}

	if (index >= getLength())
	{
		pushBack(value);
		delete insertedNode;
		return false;
	}
	
	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;

	if (currentNode->previous == nullptr)
	{
		insertedNode->previous = currentNode->previous;
		insertedNode->next = currentNode;
		currentNode->previous = insertedNode;
		m_head = insertedNode;

	}

	else
	{
		insertedNode->next = currentNode;
		insertedNode->previous = currentNode->previous;
		currentNode->previous->next = insertedNode;
		currentNode->previous = insertedNode;
	}

	m_nodeCount++;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* currentNode = m_head;
	int count = 0;

	if (isEmpty())
		return false;
	while (currentNode->data != value)
	{
		currentNode = currentNode->next;

		if (count > getLength())
			break;
		count++;

		if (currentNode == nullptr)
			return false;
	}

	if (currentNode->next == nullptr)
	{
		currentNode->previous->next = nullptr;
		m_tail = currentNode->previous;
	}


	else if (currentNode->previous == nullptr)
	{
		currentNode->next->previous = nullptr;
		m_head = currentNode->next;
	}


	else
	{
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
	}

	

	m_nodeCount--;
	delete currentNode;
	currentNode = nullptr;

	return true;
}

template<typename T>
inline void List<T>::print() const
{
	Iterator<T> iter = begin();
	while (iter != end())
	{
		std::cout << *iter << std::endl;
		++iter;
	}
	std::cout << "Node Count: " << m_nodeCount << std::endl;
}

template<typename T>
inline void List<T>::initialize()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return (begin() == nullptr);
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	iter = begin();
	for (int i = 0; i < index; i++)
		++iter;

	return false;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy();
	List<T>* newList = new List<T>();

	Iterator<T> iter = begin();
	while (iter != end())
	{
		pushFront(*iter);
		++iter;
	}
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	Node<T>* key = m_head->next;
	Node<T>* currentNode;

	while (key != nullptr)
	{
		currentNode = key->previous;

		while (currentNode->previous == nullptr && currentNode->data > key->data)
		{
			if (currentNode->data > key->data)
			{
				currentNode->next = currentNode;

				if (currentNode->previous == nullptr)
					break;

				currentNode = currentNode->previous;
			}
			currentNode->next = key;
		}
		key = key;
	}
}
