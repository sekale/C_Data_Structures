//
//  main.cpp
//  Hash_Table
//
//  Created by Siddhant Ekale on 7/31/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <string>
#include "hash.h"


using namespace std;

int main(int argc, const char * argv[])
{
    hash_table HashTableInstance;
    
    HashTableInstance.addItem("Kevin",2);
    HashTableInstance.addItem("Siddhant",1);
    HashTableInstance.addItem("Mark",3);
    HashTableInstance.addItem("Bourne",4);
    HashTableInstance.addItem("Spacey",5);
    HashTableInstance.PrintHashTable();
}

