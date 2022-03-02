#pragma once
template <typename T>
class Node {
public:
	//Storage Container For my Data 
	Node() { data = 0, next = nullptr, previous = nullptr; };
	~Node() {};
	Node(T value) { data = value, next = nullptr, previous = nullptr; };
	

public:
	//Keeps tabs on the next node in front of it 
	Node<T>* next;
	//Keeps tabs on the node before it 
	Node<T>* previous;
	//Data beinbg presented 
	T data;
};