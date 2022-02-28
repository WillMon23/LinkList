#pragma once
#include "Node.h"
template <typename T>
class Iterator {
public:
	Iterator() { m_current = new Node<T>(); };
	Iterator(Node<T>* node) { m_current = node; };

	/// <summary>
	/// overloads the plus plus oprator
	/// It'll instead change the current node to be it's next node 
	/// When applicable
	/// <summary>
	Iterator<T> operator++();

	/// <summary>
	/// overloads the minus minus oprator
	/// It'll instead change the current node to be it's previous node 
	/// When applicable
	/// <summary>
	Iterator<T> operator--();

	/// <summary>
	/// Overloads the equals equals oporator 
	/// It'll instead comapre current nodes in itoration
	/// <summary>
	bool operator==(const Iterator<T>& iter) const;

	/// Overloads the not equals oporator 
	/// It'll instead comapre current nodes in itoration
	/// <summary>
	bool operator!=(const Iterator<T>& iter) const;

	/// Overloads the star oporator 
	/// It'll instead display the data in that current node 
	/// <summary>
	T operator*();

private:
	// preivate current node 
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	//if the current node is not a nullptr 
	if(m_current != nullptr)
		//To the next node on the list
		return m_current = m_current->next;
	// if not it just returns a new iterator
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{	
	//If the current node does not equal a nullptr 
	if (m_current != nullptr)
		//To the prevois node on the list
		return m_current = m_current->previous;
	// if not it just returns a new iterator
	return Iterator<T>();
}

template<typename T>
inline bool Iterator<T>::operator==(const Iterator<T>& iter) const
{
	//if the itorated nodes are both equaled to nullpree
	if (iter.m_current == nullptr && m_current == nullptr)
		//return true
		return true;
	//but if the current node equals null or the the other node equals nullptr
	else if (iter.m_current == nullptr || m_current == nullptr)
		//return false
		return false;
	//If both nodes data are the same 
	return (iter.m_current->data == m_current->data);
}

template<typename T>
inline bool Iterator<T>::operator!=(const Iterator<T>& iter) const
{
	//if the itorated nodes are both equaled to nullpree
	if (iter.m_current == nullptr && m_current == nullptr)
		//return false
		return false;
	//but if the current node equals null or the the other node equals nullptr
	else if (iter.m_current == nullptr || m_current == nullptr)
		//return true
		return true;

	//if the data for both node are diffrent 
	return (iter.m_current->data != m_current->data);	
}

template<typename T>
inline T Iterator<T>::operator*()
{
	//Current data in the node 
	return	m_current->data;
}
