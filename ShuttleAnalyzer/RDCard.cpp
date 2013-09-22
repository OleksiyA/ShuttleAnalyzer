//
//  RDCard.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include "RDCard.h"

RDCard::RDCard()
{
    this->iIdentifier = NULL;
}

RDCard::RDCard(char* identifier,int index):iIdentifier(identifier),iIndex(index)
{
    
}

RDCard::~RDCard()
{
    delete this->iIdentifier;
    this->iIdentifier = NULL;
}

#pragma mark RDHashable methods
unsigned int RDCard::generateHash()
{
    char buf[256];
    sprintf(buf, "%d",this->iIndex);
    unsigned int hash = this->generateHashForString(buf);
    
    return hash;
}