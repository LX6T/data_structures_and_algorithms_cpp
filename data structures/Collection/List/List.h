//
// Created by alex on 16/09/2022.
//

#include <string>
#include "../Collection.h"

#pragma once


class List : virtual public Collection
{
protected:
    int mSize;
public:

    virtual int get(int i) const = 0;

    virtual void set(int i, int x) = 0;

    virtual void swap(int i, int j) = 0;

    virtual void insert(int i, int x) = 0;

    virtual void remove(int i) = 0;

    virtual void print() const = 0;

};
