//
//  RDRound.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov. All rights reserved.
//

#include "RDRound.h"

RDRound::RDRound(RDItemsContainer<RDCard>& input):iInputCards(input)
{
    
}

void RDRound::run()
{
    while(true)
    {
        //1. Take the top card off the deck and set it on the table
        RDCard* card = iInputCards.removeTopItem();
        if(!card)
        {
            break;
        }
        iOutputCards.addItemToTheTop(card);
        
        //2. Take the next card off the top and put it on the bottom of the deck in your hand.
        card = iInputCards.removeTopItem();
        if(!card)
        {
            break;
        }
        iInputCards.addItemToTheEnd(card);
    }
}

RDItemsContainer<RDCard>* RDRound::roundResult()
{
    return &(this->iOutputCards);
}