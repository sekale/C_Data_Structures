//
//  linked_list.h
//  Linked_List_Project_2
//
//  Created by Siddhant Ekale on 9/5/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#ifndef __Linked_List_Project_2__linked_list__
#define __Linked_List_Project_2__linked_list__

#include <iostream>
using namespace std;
typedef struct LinkedListNode
{
    int value;
    LinkedListNode *next = NULL;
}Node;

class LinkedList
{
    private:
        Node *head;
    public:
    
        LinkedList()
        {
            head = NULL;
        }
    
        Node *get_head()
        {
            return head;
        }
    
    
        Node *create_node(int value)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node -> value = value;
            new_node -> next = NULL;
            
            return new_node;
        }
    
        void push(LinkedListNode *node)
        {
            Node *runner_node = head;
            if(head == NULL)
            {
                head = node;
            }
            
            else
            {
                while(runner_node -> next != NULL)
                {
                    runner_node = runner_node -> next;
                }
                
                runner_node -> next = node;
            }
        }
    
        void print_list()
        {
            Node *runner_node = head;
            
            while(runner_node != NULL)
            {
                cout << runner_node -> value;
                runner_node = runner_node -> next;
            }
        }
};


#endif /* defined(__Linked_List_Project_2__linked_list__) */
