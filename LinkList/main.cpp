#include "List.h"
#include <iostream>

int main() {
	List<int>* list = new List<int>();

	List<int>* list2 = new List<int>();
	
	list->insert(1, -1);
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

	list2 = list;

	if (list->contains(100))
		std::cout << "TRUE" << std::endl;

	list->print();

	list->remove(33);

	list->sort();

	list2->print();

	return 0;
}