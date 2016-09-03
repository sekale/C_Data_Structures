//
//  main.cpp
//  STL_Introduction
//
//  Created by Siddhant Ekale on 9/3/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include "Vector.h"

using namespace std;
template <typename data_type>

data_type square(data_type x)
{
    return x*x;
}

template<typename BoVectorType>

BoVector<BoVectorType> operator*(BoVector<BoVectorType>&rhs1, BoVector<BoVectorType>&rhs2)
{
    BoVector<BoVectorType> return_element;
    for(int i = 0; i < rhs1.getSize(); i++)
    {
        return_element.push(rhs1.get(i) * rhs2.get(i));
    }
    
    return return_element;
}

int main(int argc, const char * argv[])
{
    cout << square<int>(5) << endl;
    cout << square<double>(5.5) << endl;
    
    BoVector<int> bv;
    bv.push(1);
    bv.push(2);
    bv.push(3);
    bv.push(4);
    bv.print_Vector();
    
    //square bv tries to square the vector by passing it as an argument
    //we overloaded the * operator for bv vector multiplication
    
    bv = square(bv);
    bv.print_Vector();

    
    return 0;
}



