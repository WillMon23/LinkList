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
	/// <summary>
	/// Meant to destroy what reamins in the m_head node
	/// as well whats in the m_tail as well as reseting the 
	/// the m_nodeCount to zero 
	/// </summary>
	void destroy();

	/// <summary>
	/// Alocates the start of the Iteration with 
	/// </summary>
	/// <returns></returns>
	Iterator<T> begin() const;

	/// <summary>
	/// Alocates the the end node to the Iterator
	/// </summary>
	/// <returns></returns>
	Iterator<T> end() const;

	/// <summary>
	/// Looks for the node through the itarator 
	/// in order to find the node with the value in it 
	/// Returns true if its in the list
	/// <summary>
	bool contains(const T object) const;

	/// <summary>
	/// Pushes a new node with the value in the front of the nodes 
	/// <summary>
	void pushFront(const T& value);

	/// <summary>
	/// Pushes a new node to the End of the list 
	/// <summary>
	void pushBack(const T& value);

	/// <summary>
	/// Inserts a new node at any given index of the 
	/// List 
	/// <summary>
	bool insert(const T& value, int index);

	/// <summary>
	/// Removes the first node with the value in the argument
	/// <summary>
	bool remove(const T& value);

	/// <summary>
	/// Prints the values in the whole list 
	/// <summary>
	void print() const;
	
	/// <summary>
	/// Places a defult vavlue to the list of values 
	/// <summary>
	void initialize();

	/// <summary>
	/// Checks to see if the list contains nodes 
	/// Retuns true if it does 
	/// Retuns false other wise 
	/// <summary>
	bool isEmpty()const;

	/// <summary>
	/// Grabs the data in the given index 
	/// Sets that iteration back to it's 
	/// Current Node
	/// <summary>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// Get the currnet node count 
	/// Retuns it's current value 
	/// <summary>
	int getLength() const { return m_nodeCount; };

	/// <summary>
	/// Sets the value of one interator to be the others 
	/// Iterators values 
	/// <summary>
	const List<T>& operator=(const List<T>& otherList);

	/// <summary>
	/// Sorts all the data stored in the list 
	/// Sorts the Data by Bubble sort 
	/// <summary>
	void sort();

private:
	//Start of the list 
	Node<T>* m_head;

	//The End of the list
	Node<T>* m_tail;
	
	//Total count of nodes currently added to the list 
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
	//staring iteration node
	Iterator<T> inter =  begin();

	//will the iterator is not at the last node 
	while (inter != end())
	{
		//if the current node in the iterator equlas that of the object
		if (*inter == object)
			//return true 
			return true;
		//if not it just continues to iterate 
		++inter;
	}
	//if it goes through all of the iteration nodes then jsut retun false
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//New inserted node
	Node<T>* pushInsert = new Node<T>(value);

	//if the list of nodes is empty
	if (isEmpty())
	{
		//Sets the new node to the head and the tail of the list
		m_head = pushInsert;
		m_tail = pushInsert;
	}
	//other wise 
	else
	{
		//Sets the new node to be the head previous
		m_head->previous = pushInsert;
		//sets the new node next node to be the current head node 
		pushInsert->next = m_head;
		//Sets the new node to be the new head 
		m_head = pushInsert;
	}
	//Add one to the current count of nodes to the list
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	// New inserted node
	Node<T>* pushInsert = new Node<T>(value);

	//if the list of nodes is empty
	if (isEmpty())
	{
		//Sets the new node to the head and the tail of the list
		m_head = pushInsert;
		m_tail = pushInsert;
	}
	//other wise 
	else
	{
		//Sets the new node to be the tails next 
		m_tail->next = pushInsert;
		//sets the new node previus node to be the current tail node 
		pushInsert->previous = m_tail;
		//Sets the new node to be the new tail 
		m_tail = pushInsert;
	}
	//Add one to the current count of nodes to the list
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Current Node Location
	Node<T>* currentNode = m_head;

	//Inserting Node 
	Node<T>* insertedNode = new Node<T>(value);

	//If list is Empty
	if (isEmpty())
	{
		//Poppulate it with that node in both the head and the tail of the list
		m_head = insertedNode;
		m_tail = insertedNode;
		//Add one to the current count of nodes to the list
		m_nodeCount++;
		return false;
	}
	//If the index location is larger then the current node length
	if (index >= getLength())
	{
		//just push the node to the wnd of the list 
		pushBack(value);
		delete insertedNode;
		//returns false cuz it's not in the right locattion 
		return false;
	}
	
	//Itorate through the list until it reaches the index 
	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;

	//check to see if the current node previous node is pointing null
	if (currentNode->previous == nullptr)
		//Then just push it to the front of the list
		pushFront(value);
	//Other wise
	else
	{
		//make the new node next node to be the current node 
		insertedNode->next = currentNode;
		//The new nodes previous node be the current nodes previous node 
		insertedNode->previous = currentNode->previous;
		//Current node previous next is the new inserted node 
		currentNode->previous->next = insertedNode;
		//Current nodes previous is now the new inseted node 
		currentNode->previous = insertedNode;
	}
	//Add one to the current count of nodes to the list
	m_nodeCount++;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Current Node Location
	Node<T>* currentNode = m_head;
	int count = 0;

	//if the list is empty 
	if (isEmpty())
		//returns false
		return false;
	
	//if the data in the current node does not match the value 
	while (currentNode->data != value)
	{
		//Makes the current node to be the current node next node 
		currentNode = currentNode->next;
		//if the current node is a nullptr
		if (currentNode == nullptr)
			//just return false
			return false;
	}
	
	//If the current node next node is nullpte 
	if (currentNode->next == nullptr)
	{

		//Remove the previous nodes attachment with this node  
		currentNode->previous->next = nullptr;
		//Then changes the tail node to be the currents previous node to be it's new node 
		m_tail = currentNode->previous;
	}

	//If the current node previous node is nullpte 
	else if (currentNode->previous == nullptr)
	{
		//Remove the next nodes attachment with this node  
		currentNode->next->previous = nullptr;
		//Then changes the head node to be the currents next node to be it's new node 
		m_head = currentNode->next;
	}

	//Other Wise 
	else
	{
		//then connects the nodes around the the current node rogether
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
	}

	//subtracts one from the node count
	m_nodeCount--;
	delete currentNode;
	currentNode = nullptr;

	return true;
}

template<typename T>
inline void List<T>::print() const
{
	Iterator<T> iter = begin();
	while (iter != nullptr)
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
	return (m_head == nullptr);
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
	//destroys everthing in the list if ny
	destroy();
	//if any of the list is empty 
	if (otherList.isEmpty() || isEmpty())
		//Just returns an empty listt
		return List<T>();
	//MAkes a new iterator seting its current node from the beginning
	Iterator<T> iter = begin();
	//While it's not at the end 
	while (iter != end())
	{
		//Push the data to the beginning of the lsit 
		pushFront(*iter);
		//Goes to the next node in the itoration
		++iter;
	}
	//Retuns this list 
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	//The node that will be compared to
	Node<T>* keyNode = m_head;
	
	//While the key node does not equal to nullptr 
	while (keyNode != nullptr)
	{
		//Current node be comapred to the key node 
		Node<T>* currentNode = keyNode->next;
		//While the current node does not equal to nullptr 
		while (currentNode != nullptr)
		{
			//Inorder to exchange without issues 
			T key = keyNode->data;
			//if current node data is less then or equal to the key node data 
			if (currentNode->data <= key)
			{
				//Exchange the data from the current node to the key node
				keyNode->data = currentNode->data;
				//Then exchange what in the key node before  the last exchange to the current node 
				currentNode->data = key;
			}
			//Then change the current node to be the current nodes next node
			currentNode = currentNode->next;
		}
		//Then change the keynode to be the next key node 
		keyNode = keyNode->next;
	}
}
