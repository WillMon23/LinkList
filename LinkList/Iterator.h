#pragma once
#include "Node.h"
template <typename T>
class Iterator {
public:
	Iterator();
	Iterator(Node<T>* node);
	Iterator<T> operator++();
	Iterator<T> operator--();
	bool operator==(const Iterator<T>& iter) const;
	bool operator!=(const Iterator<T>& iter) const;
	T operator*();

private:
	Node<T>* m_current;
};
