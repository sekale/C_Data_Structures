//
//  main.cpp
//  Linked_List_Project_2
//
//  Created by Siddhant Ekale on 9/5/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//
//Problem 4: Elements less than number 'X' should come before and greater than should come after

#include <iostream>
#include "linked_list.h"

using namespace std;

void delete_list_node(LinkedList list, Node *delete_node);
void add_elements_to_list(LinkedList *list);
void partition_list(LinkedList *list, Node *head, int X);

int main(int argc, const char * argv[])
{
    //Node *temp;
    Node *head;
    LinkedList list;
    
    //int x = 23;
    add_elements_to_list(&list);
    cout << endl;
    //list.print_list();
    
    head = list.get_head();
    int list_size = list.get_list_size();
    cout << endl << list_size << endl;
    partition_list(&list, head, 32);
    
    return 0;
}

void partition_list(LinkedList *list, Node *head, int X)
{
    LinkedList less_than_list;
    LinkedList greater_than_list;
    
    Node *runner_node;
    runner_node = head;
    Node *temp_add_node;
    while(runner_node != NULL)
    {
        if(runner_node -> value < X)
        {
            temp_add_node = less_than_list.create_node(runner_node -> value);
            less_than_list.push(temp_add_node);
        }
        
        else
        {
            temp_add_node = greater_than_list.create_node(runner_node -> value);
            greater_than_list.push(temp_add_node);
        }
    
        runner_node = runner_node -> next;
    }
    
    Node *greater_than_list_head = greater_than_list.get_head();
    int min;
    if(greater_than_list_head != NULL)
    {
        min = greater_than_list_head -> value;

        while(greater_than_list_head != NULL)
        {
            if(min > greater_than_list_head -> value)
            {
                min = greater_than_list_head -> value;
            }
            greater_than_list_head = greater_than_list_head -> next;
        }
        
        greater_than_list_head = greater_than_list.get_head();
        
        Node *swap_element = greater_than_list_head;
        
        while(swap_element -> value != min)
        {
            swap_element = swap_element -> next;
        }
        
        greater_than_list.swap(swap_element, greater_than_list_head);
    }
    
    
    cout << endl;
    //less_than_list.print_list();
    cout << endl;
    //greater_than_list.print_list();
    
    //merging the two lists
    
    LinkedList final_list;
    
    Node *temp;
    temp = less_than_list.get_head();
    while(temp != NULL)
    {
        Node *add_node;
        add_node = final_list.create_node(temp -> value);
        final_list.push(add_node);
        temp = temp -> next;
    }
    
    temp = greater_than_list.get_head();
    
    while(temp != NULL)
    {
        Node *add_node;
        add_node = final_list.create_node(temp -> value);
        final_list.push(add_node);
        temp = temp -> next;
    }
    
    final_list.print_list();

}

void add_elements_to_list(LinkedList *list)
{
    Node *temp;
    int i = 0;
    
    for(i = 1 ; i < 100  ; i += 2)
    {
        temp = (*list).create_node(i);
        (*list).push(temp);
    }
    
    for(i = 2 ; i < 100  ; i += 2)
    {
        temp = (*list).create_node(i);
        (*list).push(temp);
    }
}

void delete_list_node(LinkedList list, Node *delete_node)
{
    delete_node -> value = delete_node -> next -> value;
    delete_node -> next = delete_node -> next -> next;
}

