//
//  main.cpp
//  Linked_List_Problem5
//
//  Created by Siddhant Ekale on 9/6/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//
//Problem 5: Two Numbers stored as Linked Lists in reverse order; Add them and return in same format as linked list
// Eg : list 1 =>  1 -> 2 -> 3
// Eg : list 2 =>  4 -> 5 -> 6
// Numbers are actually 321 and 654

#include <iostream>
#include "linked_list.h"

LinkedList add_lists(LinkedList number1, LinkedList number2);

int main(int argc, const char * argv[])
{
    LinkedList number1;
    LinkedList number2;
    
    Node *temp_node = NULL;
    //creating list 1
    temp_node = number1.create_node(8);
    number1.push(temp_node);
    
    temp_node = number1.create_node(6);
    number1.push(temp_node);
    
    temp_node = number1.create_node(8);
    number1.push(temp_node);
    
    number1.print_list();
    cout<<endl;
    
    //List has 8 -> 6 -> 8 aka Number : 868
    
    //creating list 2
    temp_node = number2.create_node(4);
    number2.push(temp_node);
    
    temp_node = number2.create_node(4);
    number2.push(temp_node);
    
    
    number2.print_list();
    cout<<endl;
    
    //List has 4 -> 4 aka Number : 44
    
    LinkedList result_list;
    result_list = add_lists(number1, number2);
    
    result_list.print_list();
    //should have 2 -> 1 -> 9 aka 912 as result
    
    return 0;
}

LinkedList add_lists(LinkedList number1, LinkedList number2)
{
    LinkedList result_list;
    
    Node *head_number1 = number1.get_head();
    Node *head_number2 = number2.get_head();
    
    Node *runner_node1 = head_number1;
    Node *runner_node2 = head_number2;
    
    Node *list3_node;
    
    int number1_size = number1.get_list_size();
    int number2_size = number2.get_list_size();
    
    int max_run_pos = (number1_size > number2_size) ? number2_size : number1_size;
    int added_value = 0;
    int counter = 0;
    int carry_over = 0;
    int value_create = 0;
    //least list length to be traversed while adding both lists together
    //for example list a : 9 -> 6 -> 8 list b: 4 -> 5
    //we only want to add 9 and 4 and then carry over 1 and add 6 and 5
    //remaining carry over and the last number addition will be taken care after this while loop
    while(counter < max_run_pos)
    {
        value_create = runner_node1 -> value + runner_node2 -> value + carry_over;
        if(value_create >= 10)
        {
            carry_over = 1;
        }
        
        else{
            carry_over = 0;
        }
        
        value_create = value_create % 10;
        list3_node = result_list.create_node(value_create);
        result_list.push(list3_node);
        
        runner_node1 = runner_node1 -> next;
        runner_node2 = runner_node2 -> next;
        
        counter++;
    }
    //while any of the list still have numbers to be added
    while(runner_node1 != NULL)
    {
        value_create = runner_node1 -> value + carry_over;
        
        if(value_create >= 10)
        {
            carry_over = 1;
        }
        
        else
        {
            carry_over = 0;
        }
        
        value_create = value_create % 10;
        list3_node = result_list.create_node(value_create);
        result_list.push(list3_node);
        
        runner_node1 = runner_node1 -> next;
        
    }
    
    while(runner_node2 != NULL)
    {
        value_create = runner_node2 -> value + carry_over;
        
        if(value_create >= 10)
        {
            carry_over = 1;
        }
        
        else
        {
            carry_over = 0;
        }
        
        value_create = value_create % 10;
        list3_node = result_list.create_node(value_create);
        result_list.push(list3_node);
        
        runner_node2 = runner_node2 -> next;
    }
    
    //if after all additions a carry over is left there is still a 1 to add to the end of the result list
    if(carry_over == 1)
    {
        list3_node = result_list.create_node(1);
        result_list.push(list3_node);
    }
    
    return result_list;
}

