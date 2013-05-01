//
//  RDHashable.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDHashable__
#define __ShuttleAnalyzer__RDHashable__

#include <iostream>

class RDHashable
{
protected:
    char*   generateHashForData(const char* data);
    
public:
    virtual char*   generateHash();
};

#endif /* defined(__ShuttleAnalyzer__RDHashable__) */
