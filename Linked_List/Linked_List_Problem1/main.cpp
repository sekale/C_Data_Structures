//
//  main.cpp
//  Linked_List_Problem1
//
//  Created by Siddhant Ekale on 9/5/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//
//Removing Duplicates From An Unsorted Linked List

#include <iostream>
#include <set>
#include <forward_list>
#include <unordered_set>

using namespace std;

void add_duplicates_to_list(forward_list<int> *mylist)
{
    for(int i = 0; i < 10; i++)
    {
        mylist -> emplace_front(5);
        mylist -> emplace_front(4);
        mylist -> emplace_front(3);
        mylist -> emplace_front(2);
    }

}

int main(int argc, const char * argv[])
{
    forward_list<int> mylist;
    //adding duplicate elements to the list
    add_duplicates_to_list(&mylist);
    
    forward_list<int>::iterator itr;
    
    for(itr = mylist.begin();itr != mylist.end(); itr++)
    {
        cout << *itr;
    }
    
    //Code to remove duplicate list elements using hash table implementation
    
    unordered_set<int> uset;
    for(itr = mylist.begin() ;itr != mylist.end(); itr++)
    {
        uset.insert(*itr); //inserting each element in hash table
    }
    
    unordered_set<int>::iterator uset_itr;
    cout << endl;
    
    //printing each element in unordered set (Hash Table) from begin to end
    for(uset_itr = uset.begin() ; uset_itr != uset.end(); uset_itr++)
    {
        cout << *uset_itr;
    }
    
    forward_list<int> duplicate_free_mylist;
    
    //adding each element to duplicate free list
    for(uset_itr = uset.begin() ; uset_itr != uset.end(); uset_itr++)
    {
        duplicate_free_mylist.emplace_front(*uset_itr);
    }
    cout << endl;
    
    //printing duplicate free list
    for(itr = duplicate_free_mylist.begin() ;itr != duplicate_free_mylist.end(); itr++)
    {
        cout << *itr;
    }
    
    return 0;
}

