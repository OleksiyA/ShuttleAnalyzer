//
//  RDShuttler.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#ifndef __ShuttleAnalyzer__RDShuttler__
#define __ShuttleAnalyzer__RDShuttler__

#include <iostream>
#include "RDItemsContainer.h"
#include "RDCard.h"

class RDShuttler
{
    RDItemsContainer<RDCard>        iCards;
    
public:
    RDShuttler(RDItemsContainer<RDCard>& inputCardsSequence);
    void shuttle();
    RDItemsContainer<RDCard>& sequence();
};

#endif /* defined(__ShuttleAnalyzer__RDShuttler__) */
