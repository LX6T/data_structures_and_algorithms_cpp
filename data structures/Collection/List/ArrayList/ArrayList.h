//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include <vector>
#include "../List.h"

#pragma once

class ArrayList : virtual public List
{
private:
    int mSize;
    int mCapacity;
    int* mArray;

public:

    /*  Constructors  */
    ArrayList();
    ArrayList(const int* input);

    /*  Collection methods  */
    int size() const;
    bool isEmpty() const;
    void add(int x);        // insert(mSize, x)
    void clear();
    void print() const;

    /*  List methods  */
    void insert(int i, int x);
    void remove(int i);
    int get(int i) const;
    void set(int i, int x);
    void swap(int i, int j);

};


/* ===== CONSTRUCTORS ===== */

ArrayList::ArrayList()
{
    mSize = 0;
    mCapacity = 10;
    mArray = new int[mCapacity];
}

ArrayList::ArrayList(const int* input)
{
    mSize = 0;

    while (input[mSize] != END)
    {
        mSize++;
    }
    mCapacity = mSize * 2;

    mArray = new int[mCapacity];

    for (int i = 0; i < mSize; ++i)
    {
        mArray[i] = input[i];
    }
}


/* ===== COLLECTION METHODS ===== */

int ArrayList::size() const
{
    return mSize;
}

bool ArrayList::isEmpty() const
{
    return mSize == 0;
}

void ArrayList::add(int x)
{
    insert(mSize, x);
}

void ArrayList::clear()
{
    mSize = 0;
    mCapacity = 10;
    mArray = new int[10];
}

void ArrayList::print() const
{
    for (int i = 0; i < mSize; ++i)
    {
        std::cout << mArray[i] << " ";
    }

    std::cout << std::endl;
}


/* ===== LIST METHODS ===== */

void ArrayList::insert(int i, int x)
{
    if (i >= mCapacity)
    {
        mCapacity *= 2;
        int* newArray = new int[mCapacity];
        for (int j = 0; j < mSize; ++j)
        {
            newArray[j] = mArray[j];
        }
        delete[] mArray;
        mArray = newArray;
    }

    mArray[mSize] = x;

    for (int j = mSize; j > i; --j)
    {
        swap(j, j - 1);
    }

    mSize++;
}

void ArrayList::remove(int i)
{
    for (int j = i; j < mSize; ++j)
    {
        swap(j, j + 1);
    }

    mSize--;
}

int ArrayList::get(int i) const
{
    return mArray[i];
}

void ArrayList::set(int i, int x)
{
    mArray[i] = x;
}

void ArrayList::swap(int i, int j)
{
    int a = mArray[i];
    int b = mArray[j];
    mArray[i] = b;
    mArray[j] = a;
}
