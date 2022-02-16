#include "List.h"
#include <iostream>

void main() {
	List<int>* list = new List<int>();

	List<int>* list2 = new List<int>();
	

	list->pushFront(10);
	list->pushFront(20);
	list->pushFront(30);
	list->pushFront(40);

	list = list2;



	list->print();

	list->insert(2, 3);
	list->remove(40);

	list->remove(100);
	list->pushFront(100);
	list->pushFront(100);
	list->pushFront(100);
	list->pushFront(100);
	list->pushFront(100);
	list->pushFront(100);

	list2->print();
}