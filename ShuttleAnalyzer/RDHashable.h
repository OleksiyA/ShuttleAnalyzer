//
//  RDHashable.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#ifndef __ShuttleAnalyzer__RDHashable__
#define __ShuttleAnalyzer__RDHashable__

#include <iostream>

class RDHashable
{
protected:
    unsigned int generateHashForString(const char *string);
    
public:
    virtual unsigned int generateHash();
};

#endif /* defined(__ShuttleAnalyzer__RDHashable__) */
