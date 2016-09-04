//
//  main.cpp
//  Unordered Associative Containers (Hashtables)
//
//  Created by Siddhant Ekale on 9/3/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>

//Unordered set can be used as a hash table
//just like dictionary in Python
//Best case Time Search is O(1) constant time
//But worst case can become O(n) if all the elements are routed to the same bucket

using namespace std;
typedef pair<string, string> Name;

//Custom Hash Function
struct custom_hash
{
    //Declaration for the custom has function
    size_t operator()(const Name &name)const
    {
        return hash<string>()(name.first) ^ hash<string>()(name.second);
    }
};

int main(int argc, const char * argv[])
{
    unordered_map<char,string> day = {{'S',"Sunday"}, {'M',"Monday"}};
    unordered_map<char,string>::iterator itr = day.begin();
    
    day.insert(make_pair('T',"Tuesday"));
    
    cout << day['S'] << endl;
    day['W'] = "Wednesday";
    cout << day['W'] << endl;
    cout << day['T'] << endl;
    
    //http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210?pgno=3
    //Now we use a custom hash function in case a key that cannot be interpreted by the std::hash<key> function
    
    unordered_map<Name,int, custom_hash> ids;
    
    ids[Name("Mark","Y")] = 12;
    ids[Name("Mark","W")] = 13;
    
    auto ii = ids.begin();
    
    for(;ii != ids.end(); ii++)
    {
        cout << ii -> first.first;
        cout << ii -> first.second;
        cout << ii -> second;
    }
    
    return 0;
}

