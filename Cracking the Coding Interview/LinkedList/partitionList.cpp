#include <iostream>
#include "linkedList.h"

#define DEBUG

using namespace std;
listNode *findLastNode(listNode *head);
linkedList *partitionList(linkedList *list1, int value);

int main()
{
	//Driver Program
	linkedList *list1 = new linkedList();
	(*list1).addNode(2);
	(*list1).addNode(3);
	(*list1).addNode(4);
	(*list1).addNode(7);
	(*list1).addNode(6);
	(*list1).addNode(1);
	(*list1).addNode(10);

	listNode *tail = findLastNode(list1 -> head);
	linkedList *partitionedList = partitionList(list1, 6);

#ifdef DEBUG
	(*list1).printList();
	(*partitionedList).printList();
#endif
}

listNode *findLastNode(listNode *head)
{
	while(head -> next != NULL)
	{
		head = head -> next;
	}
	return head;
}

linkedList *partitionList(linkedList *list1, int value)
{
	linkedList *beforeList = new linkedList();
	linkedList *afterList =  new linkedList();

	listNode *beforeListTail = NULL;
	listNode *afterListTemp = NULL;

	listNode *listTemp = list1 -> head;

	while(listTemp != NULL)
	{
		if(listTemp -> data < value)
		{		
			beforeListTail = (*beforeList).addNode(listTemp -> data);
		}

		else
		{
			(*afterList).addNode(listTemp -> data);
		}
		listTemp = listTemp -> next;
	}

	afterListTemp = afterList -> head;

	while(afterListTemp != NULL)
	{
		beforeListTail -> next = (*beforeList).createNode(afterListTemp -> data);
		beforeListTail = beforeListTail -> next;
		afterListTemp = afterListTemp -> next;
	}
	return beforeList;
}