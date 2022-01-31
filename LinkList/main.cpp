#include "List.h"

void main() {
	List<int>* list = new List<int>();

	list->pushFront(1);
	list->pushFront(2);
	list->pushFront(3);


	list->print();
}