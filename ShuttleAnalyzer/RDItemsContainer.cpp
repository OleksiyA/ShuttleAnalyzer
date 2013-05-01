//
//  RDItemsContainer.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#include "RDItemsContainer.h"

template<typename T> RDItemsContainer<T>::RDItemsContainer()
{
    
}


template<typename T> RDItemsContainer<T>::RDItemsContainer(RDItemsContainer<T>& copyFromContainer)
{
    
}

template<typename T> RDItemsContainer<T>::RDItemsContainer(int numberOfItems)
{
    
}

#pragma mark RDHashable methods
template<typename T> char*   RDItemsContainer<T>::generateHash()
{
    return NULL;
}
