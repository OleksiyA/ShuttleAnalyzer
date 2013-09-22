//
//  RDShuttler.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include "RDShuttler.h"

RDShuttler::RDShuttler(RDItemsContainer<RDCard>& inputCardsSequence):iCards(inputCardsSequence)
{
    
}

void RDShuttler::shuttle()
{
    
}

RDItemsContainer<RDCard>& RDShuttler::sequence()
{
    return this->iCards;
}