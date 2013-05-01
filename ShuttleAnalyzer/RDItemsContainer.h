//
//  RDItemsContainer.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDItemsContainer__
#define __ShuttleAnalyzer__RDItemsContainer__

#include <iostream>
#include "RDHashable.h"
#include "RDItem.h"

template<typename T> class RDItemsContainer:public RDHashable
{
    
public:
    RDItemsContainer();
    RDItemsContainer(RDItemsContainer<T>& copyFromContainer);
    RDItemsContainer(int numberOfItems);
    
    virtual char*   generateHash();
};

#include "RDItemsContainer.cpp"

#endif /* defined(__ShuttleAnalyzer__RDItemsContainer__) */
