//
//  RDCard.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDCard__
#define __ShuttleAnalyzer__RDCard__

#include <iostream>
#include "RDHashable.h"

class RDCard: public RDHashable
{
    char*       iIdentifier;
    size_t      iIndex;
    
public:
    virtual char*   generateHash();
};

#endif /* defined(__ShuttleAnalyzer__RDCard__) */
