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
    
    for(int i = 0; i < tablesize; i++)
    {
        //NOTE : WILL PRINT ONLY THE FIRST ELEMENT OF EVERY INDEX IN THE HASH TABLE
        number_of_items_current_index = NumItemsAtIndex(i);
        cout << "Item(s) at Index: " << i <<  "\n";
        cout << HashTable[i] -> name << "\n";
        cout << HashTable[i] -> id <<"\n";
        cout << "Number of Items = " << number_of_items_current_index << endl;
    }
}

int hash_table::NumItemsAtIndex(int index)
{
    int count = 0;
    count = count + 1;
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
        cout << "hash = " << hash;
    }
    
    index = hash % tablesize;
    return index;
    
}

