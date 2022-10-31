//
// Created by alex on 31/10/2022.
//

#pragma once

#include "../Set.h"

class HashSet : Set
{
private:
    int mSize;
    int mCapacity;

public:

    /*  Constructors  */
    HashSet();

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

HashSet::HashSet()
{
    mSize = 0;
    mCapacity = 16;
}


/* ===== COLLECTION METHODS ===== */

int HashSet::size() const
{
    return mSize;
}

bool HashSet::isEmpty() const
{
    return mSize == 0;
}

void HashSet::add(int x)
{
    // TODO implement method
}

void HashSet::clear()
{
    // TODO implement method
}

void HashSet::print() const
{
    // TODO implement method
}


/* ===== SET METHODS ===== */

bool HashSet::contains(int x)
{
    // TODO implement method
}

void HashSet::remove(int x)
{
    // TODO implement method
}
