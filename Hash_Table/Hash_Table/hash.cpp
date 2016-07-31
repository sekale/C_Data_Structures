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

hash_table::hash_table()
{
    tablesize = 100;
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

