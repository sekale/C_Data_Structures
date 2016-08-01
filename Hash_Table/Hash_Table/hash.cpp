//
//  main.cpp
//  Hash_Table
//
//  Created by Siddhant Ekale on 7/31/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "hash.h"

using namespace std;

//Constructor to initialize items in the hash table
hash_table::hash_table()
{
    //tablesize = 100;
    
    for(int i = 0; i < tablesize; i++)
    {
        HashTable[i]  = new HashTableItem;
        HashTable[i]->name="";
        HashTable[i]->id=0;
        HashTable[i]->next = NULL;
    }
}

void hash_table::PrintHashTable()
{
    int number_of_items_current_index;
    HashTableItem *hash_table_print_helper_pointer = NULL;
    
    for(int i = 0; i < tablesize; i++)
    {
        //NOTE : PRINTS ALL ELEMENTS PRESENT AT THE EACH INDEX OF HASH TABLE
        number_of_items_current_index = NumItemsAtIndex(i);
        cout <<"---------------------------------------\n";
        cout << "Number of Items = " << number_of_items_current_index << endl;
        hash_table_print_helper_pointer = HashTable[i];
        while(number_of_items_current_index >= 1)
        {
            cout << "Item(s) at Index " << i <<  "\n";
            cout << hash_table_print_helper_pointer -> name << "\n";
            cout << hash_table_print_helper_pointer -> id <<"\n";
            cout << " -- ";
            number_of_items_current_index--; //after printing the element at the index
            
            if(hash_table_print_helper_pointer->next != NULL)
            {
                hash_table_print_helper_pointer = hash_table_print_helper_pointer -> next;
            }
        }
        cout <<"---------------------------------------\n";

    }
}

int hash_table::NumItemsAtIndex(int index)
{
    int count = 0;
    if(HashTable[index]->name!="" && HashTable[index]->id!=0)
    {
      count = count + 1;
    }
    
    while(HashTable[index] -> next != NULL)
    {
        count++;
        HashTable[index] = HashTable[index]->next;
    }
    return count;
}

void hash_table::addItem(string name, int id)
{
    int index = HashFunction(name);
    
    //if nothing is present at the index
    if(NumItemsAtIndex(index) != 0)
    {
        HashTable[index]->name=name;
        HashTable[index]->id=id;
    }
    
    //if there is already an element/element(s)
    else
    {
        HashTableItem *Ptr = HashTable[index];
        HashTableItem *newItem = new HashTableItem;
        newItem->name = name;
        newItem->id=id;
        newItem->next=NULL;
        
        while(Ptr->next != NULL)
        {
            Ptr=Ptr->next; //Go Till End of List
        }
        
        Ptr->next = newItem; //Add the new element to end of list
    }
}

int hash_table::HashFunction(string Key)
{
    int hash = 0;
    int index;

    for(int i = 0; i < Key.length() ; i++)
    {
        hash = hash + (int)Key[i];
        //cout << "hash = " << hash;
    }
    
    index = hash % tablesize;
    return index;
    
}

