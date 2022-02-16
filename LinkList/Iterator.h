#pragma once
#include "Node.h"
template <typename T>
class Iterator {
public:
	Iterator() { m_current = new Node<T>(T); };
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
	return m_current = m_current->next;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{	
	return m_current = m_current->previous;
}

template<typename T>
inline bool Iterator<T>::operator==(const Iterator<T>& iter) const
{
	if (iter.m_current == nullptr && m_current == nullptr)
		return true;

	else if (iter.m_current == nullptr || m_current == nullptr)
		return false;

	return (iter.m_current == m_current);
}

template<typename T>
inline bool Iterator<T>::operator!=(const Iterator<T>& iter) const
{
	if (iter.m_current == nullptr && m_current == nullptr)
		return false;

	else if (iter.m_current == nullptr || m_current == nullptr)
		return true;

	return (iter.m_current != m_current);	
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return	m_current->data;
}
