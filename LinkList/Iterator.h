#pragma once
#include "Node.h"
template <typename T>
class Iterator {
public:
	Iterator();
	Iterator(Node<T>* node) { m_current = node; };
	Iterator<T> operator++();
	Iterator<T> operator--();
	bool operator==(const Iterator<T>& iter) const;
	bool operator!=(const Iterator<T>& iter) const;
	T operator*();

private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	Iterator<T> temp = Iterator<T>();
	 temp.m_current = m_current->next;
	return temp;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	Iterator<T> temp = Iterator<T>();
	temp.m_current = m_current->previous;
	return temp;
}

template<typename T>
inline bool Iterator<T>::operator==(const Iterator<T>& iter) const
{
	if (iter.m_current->data == m_current->data)
		return true;
	
}

template<typename T>
inline bool Iterator<T>::operator!=(const Iterator<T>& iter) const
{
	if(iter.m_current->data == m_current->data)
		return false;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return	m_current->data;
}
