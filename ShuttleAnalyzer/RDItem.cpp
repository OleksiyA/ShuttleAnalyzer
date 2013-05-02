//
//  RDItem.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#include "RDItem.h"

template<typename T> RDItem<T>::RDItem()
{
    this->iContent = NULL;
    this->iNext = NULL;
}

template<typename T> RDItem<T>::RDItem(T* content):iContent(content)
{
    this->iNext = NULL;
}

template<typename T> RDItem<T>::~RDItem()
{
    delete this->iContent;
    this->iContent = NULL;
    delete this->iNext;
    this->iNext = NULL;
}

template<typename T> T* RDItem<T>::content()
{
    return this->iContent;
}

template<typename T> void RDItem<T>::setContent(T* newContent)
{
    this->iContent = newContent;
}

template<typename T> RDItem<T>* RDItem<T>::next()
{
    return this->iNext;
}

template<typename T> void RDItem<T>::setNext(RDItem<T>* newNext)
{
    this->iNext = newNext;
}

#pragma mark RDHashable methods
template<typename T> unsigned int RDItem<T>::generateHash()
{
    unsigned int hash = this->iContent->generateHash();
    return hash;
}
