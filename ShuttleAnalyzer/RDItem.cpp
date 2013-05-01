//
//  RDItem.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#include "RDItem.h"

template<typename T> T* RDItem<T>::content()
{
    return this->iContent;
}

template<typename T> void RDItem<T>::setContent(T* newContent)
{
    delete this->iContent;
    
    this->iContent = newContent;
}

template<typename T> RDItem<T>::RDItem()
{
    this->iContent = NULL;
}

#pragma mark RDHashable methods
template<typename T> char*   RDItem<T>::generateHash()
{
    return NULL;
}
