//
//  Vector.h
//  STL_Introduction
//
//  Created by Siddhant Ekale on 9/3/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#ifndef __STL_Introduction__Vector__
#define __STL_Introduction__Vector__

#include <iostream>
using namespace std;
template<typename T>

class BoVector
{
    T arr[1000];
    int size;
    
public:
    //Constructor
    //learnt a new way to initialize a element in a class in cpp
    BoVector():size(0) {}
    
    void push(T x)
    {
        arr[size] = x;
        size++;
    }
    
    //todo: don't know why const is used here.
    T get(int elem_pos)
    {
        return arr[elem_pos]; //returns element at particular position
    }
    
    //todo: don't know why const is used here.
    int getSize()
    {
        return size; //returns size of the current BoVector
    }
    
    void print_Vector()
    {
        for(int i = 0; i < size; i ++)
        {
            cout<<arr[i]<<endl;
        }
    }
};

#endif /* defined(__STL_Introduction__Vector__) */
