//
//  RDHashable.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include <string.h>
#include "RDHashable.h"

// Code from http://stackoverflow.com/questions/8094790/how-to-get-hash-code-of-a-string-in-c
unsigned int generateHashFunc(const char *string, size_t len)
{
    unsigned int hash = 0;
    for(size_t i = 0; i < len; ++i)
        hash = 65599 * hash + string[i];
    return hash ^ (hash >> 16);
}

unsigned int RDHashable::generateHashForString(const char *string)
{
    return generateHashFunc(string, strlen(string));
}

unsigned int RDHashable::generateHash()
{
    //to be overriden by derived classes
    return NULL;
}

