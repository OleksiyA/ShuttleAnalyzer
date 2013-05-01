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
    T*          iContent;
    
public:
    RDItem();
    
    T* content();
    void setContent(T* newContent);
    
    virtual char*   generateHash();
};

#include "RDItem.cpp"

#endif /* defined(__ShuttleAnalyzer__RDItem__) */
