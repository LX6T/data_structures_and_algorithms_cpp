//
// Created by alex on 18/09/2022.
//

#pragma once

#include "../Deque.h"
#include <vector>
#include <iostream>

class ArrayDeque : virtual public Deque
{
private:
    int mSize;
    int mCapacity;
    int* mArray;
    int mFirst;
    int mLast;

    void doubleCapacity();

public:

    ArrayDeque();
    ArrayDeque(const int* input);

    int size() const;
    bool isEmpty() const;

    int getFirst() const;
    int getLast() const;

    void push(int x);
    int pop();
    int peek() const;
    int remove();

    void add(int x);
    void addFirst(int x);
    void addLast(int x);

    int removeFirst();
    int removeLast();
    void clear();

    void print() const;

};

ArrayDeque::ArrayDeque()
{
    mSize = 0;
    mCapacity = 16;
    mArray = new int[mCapacity];
    mFirst = -1;
    mLast = -1;
}

ArrayDeque::ArrayDeque(const int* input)
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

    mFirst = 0;
    mLast = mSize - 1;
}


int ArrayDeque::size() const
{
    return mSize;
}

bool ArrayDeque::isEmpty() const
{
    return mSize == 0;
}


int ArrayDeque::getFirst() const
{
    return mArray[mFirst];
}

int ArrayDeque::getLast() const
{
    return mArray[mLast];
}


void ArrayDeque::push(int x)
{
    addFirst(x);
}

int ArrayDeque::pop()
{
    return removeFirst();
}

int ArrayDeque::peek() const
{
    return getFirst();
}

int ArrayDeque::remove()
{
    return removeFirst();
}


void ArrayDeque::add(int x)
{
    addLast(x);
}

void ArrayDeque::addFirst(int x)
{
    if (mSize == mCapacity)
        doubleCapacity();

    if (isEmpty())
    {
        mFirst++;
        mLast++;
    } else if (mFirst == 0)
    {
        mFirst = mCapacity - 1;
    } else
    {
        mFirst--;
    }

    mArray[mFirst] = x;
    mSize++;
}

void ArrayDeque::addLast(int x)
{
    if (mSize == mCapacity)
    {
        doubleCapacity();
    }

    if (isEmpty())
    {
        mFirst++;
        mLast++;
    } else if (mLast == mCapacity - 1)
    {
        mLast = 0;
    } else
    {
        mLast++;
    }

    mArray[mLast] = x;
    mSize++;
}


int ArrayDeque::removeFirst()
{
    int x = getFirst();
    if (isEmpty())
    {
        return -1;
    } else if (mFirst == mCapacity - 1)
    {
        mFirst = 0;
    } else
    {
        mFirst++;
    }

    mSize--;

    return x;
}

int ArrayDeque::removeLast()
{
    int x = getLast();
    if (isEmpty())
    {
        return -1;
    } else if (mLast == 0)
    {
        mLast = mCapacity - 1;
    } else
    {
        mLast--;
    }

    mSize--;
    return x;
}

void ArrayDeque::clear()
{
    delete[] mArray;
    mSize = 0;
    mCapacity = 16;
    mArray = new int[mCapacity];
    mFirst = -1;
    mLast = -1;
}

void ArrayDeque::doubleCapacity()
{
    int ogSize = mSize;
    int newCapacity = mCapacity * 2;
    int* newArray = new int[newCapacity];

    for (int j = 0; j < ogSize; ++j)
        newArray[j] = remove();

    delete[] mArray;
    mArray = newArray;
    mSize = ogSize;
    mCapacity = newCapacity;
    mFirst = 0;
    mLast = mSize - 1;
}


void ArrayDeque::print() const
{
    int index = mFirst;
    for (int i = 0; i < mSize; ++i)
    {
        if (index == mCapacity)
            index = 0;

        std::cout << mArray[index] << " ";
        index++;
    }

    std::cout << std::endl;
}
