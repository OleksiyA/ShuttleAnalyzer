//
//  RDResolver.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include "RDResolver.h"
#include "RDRound.h"

RDResolver::RDResolver(RDItemsContainer<RDCard>& cards,unsigned int expectedCardsHash):iCards(cards),iExpectedCardsHash(expectedCardsHash),iNumberOfRoundDone(0)
{
    
}

bool RDResolver::resolve(int maxRoundsLimit)
{
    for (int i = 0; i < maxRoundsLimit; i++) {
        iNumberOfRoundDone++;
        
        RDRound round (this->iCards);
        
        round.run();
        
        this->iCards =  *round.roundResult();
        
        unsigned int hashForCurrentCombination = this->iCards.generateHash();
        
        //assuming has will be shorter than 1000 chars
        if (hashForCurrentCombination == this->iExpectedCardsHash) {
            //resolved OK
            return true;
        }
    }
    
    return false;
}

int RDResolver::numberOfRoundsDone()
{
    return this->iNumberOfRoundDone;
}