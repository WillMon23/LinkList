#pragma once
template <typename T>
class Node {
public:
	Node() { data = 0, next = nullptr, previous = nullptr; };
	Node(T value) { data = value, next = nullptr, previous = nullptr; };

public:
	Node<T>* next;
	Node<T>* previous;
	T data;
};