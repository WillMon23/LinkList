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
	list->remove(23);
	list->remove(1);
	list->remove(2);
	list->remove(3);
	list->pushFront(11);
	list->pushFront(15);
	list->insert(123, 9);
	list->insert(123, 9);
	list->insert(123, 9);
	list->pushFront(77);

	list2 = list;

	if (list->contains(100))
		std::cout << "TRUE" << std::endl;

	list->print();

	list2->remove(123);

	list->sort();

	list2->print();

	return 0;
}