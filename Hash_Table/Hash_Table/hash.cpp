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

