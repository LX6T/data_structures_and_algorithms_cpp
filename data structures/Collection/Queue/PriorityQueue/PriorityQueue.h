//
// Created by alex on 18/09/2022.
//

#pragma once

#include <cmath>
#include "../Queue.h"

class PriorityQueue : virtual public Queue
{
private:
    static const int MAX = 1;
    static const int MIN = -1;

    int mSize;
    int mCapacity;
    int mComparator;
    int* mBinaryHeap;

    void sink(int i);
    void heapify();

public:

    /*  Constructors  */
    PriorityQueue();
    PriorityQueue(const int* input);

    /*  Collection methods  */
    int size() const;
    bool isEmpty() const;
    void add(int x);
    void clear();
    void print() const;

    /*  Queue Methods  */
//  void add(int x);        (inherited from Collection)
    int remove();
    int peek() const;

};


/* ===== CONSTRUCTORS ===== */

PriorityQueue::PriorityQueue()
{
    mSize = 0;
    mCapacity = 11;
    mCapacity = MAX;
    mBinaryHeap = new int[mCapacity];
}

PriorityQueue::PriorityQueue(const int* input)
{
    mSize = 0;

    while (input[mSize] != END)
    {
        mSize++;
    }
    mCapacity = mSize * 2;

    mBinaryHeap = new int[mCapacity];

    for (int i = 0; i < mSize; ++i)
    {
        mBinaryHeap[i] = input[i];
    }

    heapify();
}


/* ===== COLLECTION METHODS ===== */

int PriorityQueue::size() const
{
    return mSize;
}

bool PriorityQueue::isEmpty() const
{
    return mSize == 0;
}

void PriorityQueue::add(int x)
{
    if (mSize == mCapacity)
    {
        mCapacity *= 2;
        int* newBinaryTree = new int[mCapacity];
        for (int j = 0; j < mSize; ++j)
        {
            newBinaryTree[j] = mBinaryHeap[j];
        }
        delete[] mBinaryHeap;
        mBinaryHeap = newBinaryTree;
    }

    mBinaryHeap[mSize] = x;
    heapify();
    mSize++;
}

void PriorityQueue::clear()
{
    mSize = 0;
    mCapacity = 11;
    mCapacity = MAX;
    mBinaryHeap = new int[mCapacity];
}

void PriorityQueue::print() const
{
    for (int i = 0; i < mSize; ++i)
    {
        std::cout << mBinaryHeap[i] << " ";
    }

    std::cout << std::endl;
}


/* ===== QUEUE METHODS ===== */

//  void PriorityQueue::add(int x)
//  {
//    if (mSize == mCapacity)
//    {
//        mCapacity *= 2;
//        int* newBinaryTree = new int[mCapacity];
//        for (int j = 0; j < mSize; ++j)
//        {
//            newBinaryTree[j] = mBinaryHeap[j];
//        }
//        delete[] mBinaryHeap;
//        mBinaryHeap = newBinaryTree;
//    }
//
//    mBinaryHeap[mSize] = x;
//    heapify();
//    mSize++;
//  }

int PriorityQueue::remove()
{
    int front = mBinaryHeap[0];
    std::swap(mBinaryHeap[0], mBinaryHeap[mSize - 1]);
    mSize--;
    sink(0);
    return front;
}

int PriorityQueue::peek() const
{
    return mBinaryHeap[0];
}


/* ===== PRIVATE METHODS ===== */

void PriorityQueue::sink(int i)
{
    while (true)
    {
        int leaf1 = 2 * i + 1;
        int leaf2 = 2 * i + 2;
        if (mSize > leaf2)
        {
            if (mBinaryHeap[i] < mBinaryHeap[leaf2] and mBinaryHeap[leaf1] < mBinaryHeap[leaf2])
            {
                std::swap(mBinaryHeap[i], mBinaryHeap[leaf2]);
                i = leaf2;
                continue;
            } else if (mBinaryHeap[i] < mBinaryHeap[leaf1])
            {
                std::swap(mBinaryHeap[i], mBinaryHeap[leaf1]);
                i = leaf1;
                continue;
            } else
            { break; }
        } else if (mSize > leaf1)
        {
            if (mBinaryHeap[i] < mBinaryHeap[leaf1])
            {
                std::swap(mBinaryHeap[i], mBinaryHeap[leaf1]);
                i = leaf1;
                continue;
            } else
            { break; }
        } else
        { break; }
    }
}

void PriorityQueue::heapify()
{
    for (int i = std::floor(mSize / 2 - 1); i >= 0; --i)
    {
        sink(i);
    }
}
