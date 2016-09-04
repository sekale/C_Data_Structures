//
//  main.cpp
//  STL_Vector_Iterator_Implementation
//
//  Vectors in CPP are so cool!! :)
//  Created by Siddhant Ekale on 9/3/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>::iterator itr1, vector<int>::iterator itr2)
{
    for(vector<int>::iterator itr = itr1; itr != itr2; itr++)
    {
        cout<<*itr<<endl; //printing each element in the vector
    }
}

void push_random_values_vector(vector<int> *vec)
{
    vec -> push_back(4); //todo: understand the notation
    vec -> push_back(3);
    vec -> push_back(2);
    vec -> push_back(1);
}


int main(int argc, const char * argv[])
{
    vector<int> vec;
    
    push_random_values_vector(&vec); //passing vector to a function as a parameter to load values into it
    vec.push_back(5); //normally pushing stuff into the vector
    
    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end();
    
    print_vector(itr1,itr2);
    
    sort(itr1,itr2);
    
    print_vector(itr1, itr2);

    return 0;
}

