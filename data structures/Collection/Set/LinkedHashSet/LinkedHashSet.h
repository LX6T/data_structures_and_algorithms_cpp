//
// Created by alex on 31/10/2022.
//

#pragma once

#include "../Set.h"

class LinkedHashSet : Set
{
private:
    int mSize;
    int mCapacity;

public:

    /*  Constructors  */
    LinkedHashSet();

    /*  Collection methods  */
    int size() const;
    bool isEmpty() const;
    void add(int x);
    void clear();
    void print() const;

    /*  Set methods  */
    bool contains(int x);
    void remove(int x);

};


/* ===== CONSTRUCTORS ===== */

LinkedHashSet::LinkedHashSet()
{
    mSize = 0;
    mCapacity = 16;
}


/* ===== COLLECTION METHODS ===== */

int LinkedHashSet::size() const
{
    return mSize;
}

bool LinkedHashSet::isEmpty() const
{
    return mSize == 0;
}

void LinkedHashSet::add(int x)
{
    // TODO implement method
}

void LinkedHashSet::clear()
{
    // TODO implement method
}

void LinkedHashSet::print() const
{
    // TODO implement method
}


/* ===== SET METHODS ===== */

bool LinkedHashSet::contains(int x)
{
    // TODO implement method
}

void LinkedHashSet::remove(int x)
{
    // TODO implement method
}
