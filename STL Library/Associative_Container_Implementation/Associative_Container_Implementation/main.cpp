//
//  main.cpp
//  Associative_Container_Implementation
//
//  Created by Siddhant Ekale on 9/3/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

void print_set(set<int>::iterator itr1, set<int>::iterator itr2)
{
    cout <<endl ;
    for(set<int>::iterator itr = itr1; itr != itr2; itr++)
    {
            cout<<*itr<< "-->"; //printing each element in the vector
    }
}

void print_map(map<char,int>::iterator itr1, map<char,int>::iterator itr2)
{
    cout <<endl ;
    for(map<char,int>::iterator itr = itr1; itr != itr2; itr++)
    {
        cout << (*itr).first << " ==> " << (*itr).second << endl;
    }
}

int main(int argc, const char * argv[])
{
    
    //SET IMPLEMENTATION (ORDERED)
    set<int> myset;
    myset.insert(1);
    myset.insert(4);
    myset.insert(3);
    
    set<int>::iterator itr_begin = myset.begin();
    set<int>::iterator itr_end = myset.end();
    
    
    print_set(itr_begin,itr_end);
    set<int>::iterator itr;
    itr = myset.find(4); //this find takes log(n) time
    
    pair<set<int>::iterator, bool>return_value;
    return_value = myset.insert(5);
    print_set(itr_begin,itr_end);
    
    cout<<return_value.second<<endl;
    //will print 5 saying this particular iterator is at the element we just inserted.
    cout<< *(return_value.first)<<endl;
    //bool value should be true
    
    myset.erase(return_value.first);
    print_set(itr_begin,itr_end);
    
    
    //MAP IMPLEMENTATION (KEY|VALUE PAIR)
    map<char,int> mymap;
    mymap.insert(make_pair('a',1));
    
    map<char,int>::iterator it = mymap.begin();
    mymap.insert(it, make_pair('b',2));
    it = mymap.begin();
    mymap.insert(it, make_pair('c',3));
    it = mymap.begin();
    mymap.insert(it, make_pair('d',4));
    it = mymap.begin();
    
    it = mymap.end();
    mymap.insert(it, make_pair('y',5));
    
    //Regardless of it pointer map.insert always adds at the end of the map
    
    it = mymap.find('d'); //takes logn time to go
    
    map<char,int>::iterator map_begin = mymap.begin();
    map<char,int>::iterator map_end = mymap.end();
    
    print_map(map_begin,map_end);
    
    cout << endl << (*it).first; //d
    it--;
    cout << endl << (*it).first; //c
    it--;
    cout << endl << (*it).first; //b
    it--;
    cout << endl << (*it).first; //a
    
    return 0;
}

