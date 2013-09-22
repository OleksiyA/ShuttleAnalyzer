//
//  RDItemsContainer.cpp
//  ShuttleAnalyzer
//
//  Created by Oleksiy Ivanov on 5/1/13.
//  Copyright (c) 2013 Oleksiy Ivanov.
//  The MIT License (MIT).
//

#include "RDItemsContainer.h"

template<typename T> RDItemsContainer<T>::RDItemsContainer()
{
    this->iListHead = NULL;
    this->iListTail = NULL;
}

template<typename T> RDItemsContainer<T>::RDItemsContainer(RDItemsContainer<T>& copyFromContainer)
{
    this->iListHead = copyFromContainer.iListHead;
    this->iListTail = copyFromContainer.iListTail;
    
    copyFromContainer.iListHead = NULL;
    copyFromContainer.iListTail = NULL;
}

template<typename T> RDItemsContainer<T>::RDItemsContainer(int numberOfItems)
{
    this->iListHead = NULL;
    this->iListTail = NULL;
    
    for (int i = 0; i < numberOfItems; i++) {
        this->addItemToTheEnd(NULL);
    }
}

template<typename T> RDItemsContainer<T>& RDItemsContainer<T>::operator=(const RDItemsContainer<T>& copyFromContainer)
{
    this->iListHead = copyFromContainer.iListHead;
    this->iListTail = copyFromContainer.iListTail;
    
    RDItemsContainer<T>& copyFromContainerMutable = const_cast<RDItemsContainer<T>&>(copyFromContainer);
    
    copyFromContainerMutable.iListHead = NULL;
    copyFromContainerMutable.iListTail = NULL;
    
    return *this;
}

template<typename T> RDItemsContainer<T>::~RDItemsContainer()
{
    delete this->iListHead;
    this->iListHead = NULL;
    
    this->iListTail = NULL;
}

template<typename T> void RDItemsContainer<T>::addItemToTheTop(T *item)
{
    RDItem<T> *newListItem = new RDItem<T>(item);
    
    if (!this->iListHead) {
        //handle empty list
        this->iListHead = newListItem;
        this->iListTail = this->iListHead;
    } else {
        newListItem->setNext(this->iListHead);
        this->iListHead = newListItem;
    }
}

template<typename T> void RDItemsContainer<T>::addItemToTheEnd(T *item)
{
    RDItem<T>* newListItem = new RDItem<T>(item);
    
    if (!this->iListHead) {
        //handle empty list
        this->iListHead = newListItem;
        this->iListTail = this->iListHead;
    } else {
        this->iListTail->setNext(newListItem);
        this->iListTail = newListItem;
    }
}

template<typename T> T *RDItemsContainer<T>::removeTopItem()
{
    RDItem<T>* itemToRemove = this->iListHead;
    
    T *content = NULL;
    
    if (itemToRemove) {
        this->iListHead = itemToRemove->next();
        
        content = itemToRemove->content();
        itemToRemove->setContent(NULL);
        itemToRemove->setNext(NULL);
        
        delete itemToRemove;
        itemToRemove = NULL;
    }
    
    return content;
}

template<typename T> T *RDItemsContainer<T>::itemAtIndex(int index)
{
    RDItem<T>* item = this->iListHead;
    
    for (int i = 0; i < index; i++) {
        item = item->next();
        if (!item) {
            return NULL;
        }
    }
    
    return item->content();
}

#pragma mark RDHashable methods
template<typename T> unsigned int RDItemsContainer<T>::generateHash()
{
    unsigned int hash = 0;
    
    RDItem<T> *item = this->iListHead;
    
    while (item!=NULL && item!=this->iListTail) {
        unsigned int hashForItem = item->generateHash();
        
        char buf[256];
        sprintf(buf, "%d%d",hash,hashForItem);
        hash = this->generateHashForString(buf);
        
        item = item->next();
    }
    
    return hash;
}
