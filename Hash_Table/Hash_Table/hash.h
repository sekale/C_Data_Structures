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
    int tablesize;
    
    public:
    hash_table();
    int HashFunction(string Key);
};