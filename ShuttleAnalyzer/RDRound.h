//
//  RDRound.h
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#ifndef __ShuttleAnalyzer__RDRound__
#define __ShuttleAnalyzer__RDRound__

#include <iostream>
#include "RDItemsContainer.h"
#include "RDCard.h"

class RDRound
{
    RDItemsContainer<RDCard>        iInputCards;
    RDItemsContainer<RDCard>        iOutputCards;
    
public:
    RDRound(RDItemsContainer<RDCard>& input);
    void run();
    RDItemsContainer<RDCard>* roundResult();
};

#endif /* defined(__ShuttleAnalyzer__RDRound__) */
