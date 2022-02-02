#include "List.h"

void main() {
	List<int>* list = new List<int>();

	

	list->pushFront(10);
	list->pushFront(10);
	list->pushFront(10);
	list->pushFront(10);
	list->insert(100, 2);
	
	list->pushBack(100);

	list->print();
}