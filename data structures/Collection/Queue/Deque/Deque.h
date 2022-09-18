//
// Created by alex on 18/09/2022.
//

#pragma once

#include "../Queue.h"

class Deque : virtual public Queue
{
public:

    virtual void addFirst(int x) = 0;

    virtual void addLast(int x) = 0;

    virtual int removeFirst() = 0;

    virtual int removeLast() = 0;

    virtual int getFirst() const = 0;

    virtual int getLast() const = 0;


    virtual void push(int x) = 0;

    virtual int pop() = 0;

};
