#include "List.h"
#include <iostream>

void main() {
	List<int>* list = new List<int>();

	

	list->pushFront(10);
	list->pushFront(20);
	list->pushFront(30);
	list->pushFront(40);
	if (list->insert(100,3))
		std::cout << "Works!" << std::endl;
	//list->pushFront(1);

	list->print();
}