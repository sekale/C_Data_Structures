//
//  main.cpp
//  Linked_List_Project_2
//
//  Created by Siddhant Ekale on 9/5/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//
//Problem 3: Algorithm to delete a node in the middle of a singly linked list given access to only that node

#include <iostream>
#include "linked_list.h"

using namespace std;

void delete_list_node(LinkedList list, Node *delete_node);

int main(int argc, const char * argv[])
{
    Node *temp;
    Node *delete_node;
    LinkedList list;
    
    temp = list.create_node(2);
    list.push(temp);
    
    temp = list.create_node(3);
    list.push(temp);
    
    temp = list.create_node(4);
    list.push(temp);
    
    delete_node = temp; //this node needs to be deleted
    
    temp = list.create_node(5);
    list.push(temp);
    cout << endl;
    list.print_list();
    
    //assuming we do not know the size of the linked list we find the kth to last element of the linked list
    
    delete_list_node(list, delete_node);
    cout << endl;
    list.print_list();
    

    return 0;
}

void delete_list_node(LinkedList list, Node *delete_node)
{
    delete_node -> value = delete_node -> next -> value;
    delete_node -> next = delete_node -> next -> next;
}

