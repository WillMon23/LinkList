#pragma once
template <typename T>
class Node {
public:
	Node();
	Node(T value);
	Node<T>* previous;
	T date;
};