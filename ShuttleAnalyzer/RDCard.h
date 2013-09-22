//
//  RDCard.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#ifndef __ShuttleAnalyzer__RDCard__
#define __ShuttleAnalyzer__RDCard__

#include <iostream>
#include "RDHashable.h"

class RDCard: public RDHashable
{
    char *iIdentifier;
    int iIndex;
    
public:
    RDCard();
    RDCard(char *identifier,int index);
    ~RDCard();
    
    virtual unsigned int generateHash();
};

#endif /* defined(__ShuttleAnalyzer__RDCard__) */
