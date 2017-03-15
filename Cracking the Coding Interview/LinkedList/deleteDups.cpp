#include <iostream>
#include <unordered_set>
#include "linkedList.h"
#define DEBUG

void deleteDups(linkedList *opList);

int main()
{
	//Driver Program
	linkedList *list1 = new linkedList();
	(*list1).addNode(2);
	(*list1).addNode(3);
	(*list1).addNode(4);
	(*list1).addNode(2);
	(*list1).addNode(6);
	(*list1).addNode(2);
	(*list1).addNode(6);
	(*list1).addNode(9);
	(*list1).addNode(10);
	(*list1).addNode(10);
	(*list1).addNode(10);
	(*list1).addNode(10);
#ifdef DEBUG
	(*list1).printList();
	deleteDups(list1);
	cout << "\n Duplicates Free List: \n";
	(*list1).printList();
#endif
}

void deleteDups(linkedList *opList)
{
	unordered_set<int> opListTrack;
	listNode *temp = opList -> head;
	listNode *prev = NULL;

	while(temp != NULL)
	{
		if(opListTrack.find(temp -> data) != opListTrack.end())
		{
			prev -> next = temp -> next;
			free(temp);
		}
		else
		{
			opListTrack.insert(temp -> data);
			prev = temp;
		}
		temp = temp -> next;
	}
}