#include "List.h"

void main() {
	List<int>* list = new List<int>();

	

	list->insert(10, 2);
	list->insert(10, 2);
	list->insert(10, 2);
	list->insert(10, 2);
	list->insert(10, 2);
	list->insert(100, 2);
	
	//list->pushBack(100);

	list->print();
}