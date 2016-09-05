//
//  main.cpp
//  Linked_List_Project_2
//
//  Created by Siddhant Ekale on 9/5/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//
//Problem 2: Algorithm to print kth to last element of a singly linked list

#include <iostream>
#include "linked_list.h"

using namespace std;
int printKthtolastelement(LinkedList list, Node *head,int k);

int main(int argc, const char * argv[])
{
    Node *temp;
    int k  = 2;
    LinkedList list;
    
    temp = list.create_node(2);
    list.push(temp);
    
    temp = list.create_node(3);
    list.push(temp);
    
    temp = list.create_node(4);
    list.push(temp);
    
    temp = list.create_node(5);
    list.push(temp);
    
    list.print_list();
    
    //assuming we do not know the size of the linked list we find the kth to last element of the linked list
    Node *head = list.get_head();
    
    printKthtolastelement(list, head, k);

    return 0;
}

int printKthtolastelement(LinkedList list, Node *head, int k)
{
    //terminating condition
    if(head == NULL)
    {
        return 0;
    }
    
    int i = printKthtolastelement(list, head -> next, k);
    i = i + 1; //after last element this will be incremented by 1
    
    if(i == k)
    {
        cout << endl;
        cout << head -> value;
    }
    
    return i;
}

