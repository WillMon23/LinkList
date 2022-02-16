#include "List.h"
#include <iostream>

void main() {
	List<int>* list = new List<int>();

	

	list->pushFront(10);
	list->pushFront(20);
	list->pushFront(30);
	list->pushFront(40);
	if (list->insert(100,100))
	list->pushFront(1);


	list->print();

	list->insert(2, 3);
	list->remove(2);
	list->remove(40);
	list->remove(100);
	list->remove(100);
	list->remove(100);
	list->remove(10);
	list->remove(10);
	list->print();
}