//
//  RDItem.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDItem__
#define __ShuttleAnalyzer__RDItem__

#include <iostream>
#include "RDHashable.h"

template<typename T> class RDItem: public RDHashable
{
    T*                  iContent;
    RDItem<T>*          iNext;
    
public:
    RDItem();
    RDItem(T* content);
    ~RDItem();
    
    T* content();
    void setContent(T* newContent);
    
    RDItem<T>* next();
    void setNext(RDItem<T>* newNext);
    
    virtual unsigned int generateHash();
};

#include "RDItem.cpp"

#endif /* defined(__ShuttleAnalyzer__RDItem__) */
