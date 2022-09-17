//
// Created by alex on 24/08/2022.
//

#pragma once

class Node
{
private:
    Node* mPrev;
    Node* mNext;
    int mVal;
public:

    // Each node stores a mVal, plus pointers to the mNext and previous nodes
    Node(Node* prev, Node* next, int val)
    {
        this->mPrev = prev;
        this->mNext = next;
        this->mVal = val;
    }

    Node* prev()
    {
        return mPrev;
    }

    Node* next()
    {
        return mNext;
    }

    int val() const
    {
        return mVal;
    }

    void setNext(Node* newNext)
    {
        mNext = newNext;
    }

    void setPrev(Node* newPrev)
    {
        mPrev = newPrev;
    }

    void setVal(int x)
    {
        mVal = x;
    }

};