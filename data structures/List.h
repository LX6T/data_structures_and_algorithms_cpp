//
// Created by alex on 16/09/2022.
//

#include <string>

#pragma once


class List
{
protected:
    int mSize;
public:

    virtual int size() const = 0;

    virtual bool isEmpty() const = 0;

    virtual int get(int i) const = 0;

    virtual void set(int i, int x) = 0;

    virtual void swap(int i, int j) = 0;

    virtual void add(int x) = 0;

    virtual void insert(int i, int x) = 0;

    virtual void remove(int i) = 0;

    virtual void clear() = 0;

    virtual void print() const = 0;

};
