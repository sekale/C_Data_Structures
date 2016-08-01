//
//  hash.h
//  Hash_Table
//
//  Created by Siddhant Ekale on 7/31/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class hash_table
{
    private:
    static const int tablesize = 10;
    
    struct HashTableItem
    {
        string name;
        int id;
        HashTableItem *next;
    };
    
    HashTableItem *HashTable[tablesize]; //hash table holding table size elements
    
    public:
    hash_table();
    int HashFunction(string Key);
};