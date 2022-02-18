#include "List.h"
#include <iostream>

int main() {
	List<int>* list = new List<int>();

	List<int>* list2 = new List<int>();
	

	list->pushFront(50);
	list->pushFront(40);
	list->pushFront(20);
	list->pushFront(30);

	list->print();

	list->sort();

	list->print();

	return 0;
}