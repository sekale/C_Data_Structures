#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	linkedList *list1 = new linkedList();
	(*list1).addNode(2);
	(*list1).addNode(3);
	(*list1).addNode(4);
	(*list1).addNode(7);
	(*list1).addNode(9);
	(*list1).printList();
}