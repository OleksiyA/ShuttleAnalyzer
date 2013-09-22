//
//  main.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include <iostream>
#include "RDResolver.h"
#include "RDShuttler.h"
#include "RDRound.h"

int main(int argc, const char * argv[])
{
    std::cout << "Shuttle Analyzer started.\n Written by Oleksiy Ivanov <oleksiy@effectivedeveloper.com>\n";
    
    if(argc<2)
    {
        std::cout << "Please provide number of card to shuttle.\n";
        return -1;
    }
    
    //parse input parameters
    const char* cardsNumCString = argv[1];
    
    int numberOfCards = 0;
    
    sscanf(cardsNumCString, "%d", &numberOfCards);
    
    if(numberOfCards==0 || numberOfCards > 100000)
    {
        std::cout << "Please provide valid number of card to shuttle. Provided ["<< numberOfCards << "]\n";
        return -1;
    }
    
    //validate input parameters
    std::cout << "Will shutle a set of [" << numberOfCards << "] cards.\n";
    
    //create a set of ordered cards
    RDItemsContainer<RDCard> inputSequence;
    
    for(int i = 0; i < numberOfCards; i++)
    {
        inputSequence.addItemToTheEnd(new RDCard(NULL,i));
    }
    
    unsigned int hashOfTheOrderedSetOfCards = inputSequence.generateHash();
    
    std::cout << "Shuttling cards.\n";
    
    //shuttle cards one time
    RDRound roundInitialShuttle(inputSequence);
    roundInitialShuttle.run();
    
    RDItemsContainer<RDCard> messedCards(*roundInitialShuttle.roundResult());

    std::cout << "Resolving messed cards.\n";
    
    //try to resolve messed set of cards
    RDResolver resolver(messedCards,hashOfTheOrderedSetOfCards);
    
    int maxNumberOfRoundsToResolve = 1000000;
    
    bool resolved = resolver.resolve(maxNumberOfRoundsToResolve);
    
    //print result of the resolving operation
    if(resolved)
    {
        int numberOfRoundsTaken = resolver.numberOfRoundsDone();
        std::cout << "Resolved in [" << numberOfRoundsTaken << "] rounds." << std::endl;
    }
    else
    {
        std::cout << "Unable to resolve during [" << maxNumberOfRoundsToResolve << "] rounds." << std::endl;
    }
    
    return 0;
}

