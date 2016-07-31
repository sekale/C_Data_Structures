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
    int index;
    hash_table HashObj;
    // insert code here...
    cout << "Hello, World!\n";
    index = HashObj.HashFunction("Sid");
    cout << "index = " << index;
    
    return 0;
}

