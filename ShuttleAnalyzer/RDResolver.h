//
//  RDResolver.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDResolver__
#define __ShuttleAnalyzer__RDResolver__

#include <iostream>
#include "RDItemsContainer.h"
#include "RDCard.h"

class RDResolver
{
    RDItemsContainer<RDCard>        iCards;
    unsigned int                    iExpectedCardsHash;
    int                             iNumberOfRoundDone;
    
public:
    RDResolver(RDItemsContainer<RDCard>& cards,unsigned int expectedCardsHash);
    bool resolve(int maxRoundsLimit);
    int numberOfRoundsDone();
};

#endif /* defined(__ShuttleAnalyzer__RDResolver__) */
