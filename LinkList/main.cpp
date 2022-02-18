#include "List.h"
#include <iostream>

int main() {
	List<int>* list = new List<int>();

	List<int>* list2 = new List<int>();
	

	list->pushFront(3);
	list->pushFront(2);
	list->pushFront(5);
	list->pushFront(1);
	list->pushFront(1);
	list->pushFront(10);
	list->pushFront(23);
	list->pushFront(10);
	list->pushFront(11);
	list->pushFront(15);

	list->print();

	list->sort();

	list->print();

	return 0;
}