#pragma once
template <typename T>
class Node {
public:
	Node();
	Node(T value) { data = value; };

public:
	Node<T>* next;
	Node<T>* previous;
	T data;
};