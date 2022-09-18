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
    static const int END = -1;
    int mCapacity;
    std::vector<int> mData;
public:

    ArrayList();
    ArrayList(const int* input);

    int size() const;
    bool isEmpty() const;

    int get(int i) const;
    void set(int i, int x);
    void swap(int i, int j);

    void add(int x);
    void insert(int i, int x);
    void remove(int i);
    void clear();

    void print() const;
};


ArrayList::ArrayList()
{
    mSize = 0;
    mCapacity = 0;
    mData = std::vector<int>();
}

ArrayList::ArrayList(const int* input)
{
    mSize = 0;
    mData = std::vector<int>();

    while (input[mSize] != END)
    {
        mData.push_back(input[mSize]);
        mSize++;
    }
    mCapacity = mSize;
}


int ArrayList::size() const
{
    return mSize;
}

bool ArrayList::isEmpty() const
{
    return mSize == 0;
}

int ArrayList::get(int i) const
{
    return mData[i];
}

void ArrayList::set(int i, int x)
{
    mData[i] = x;
}

void ArrayList::swap(int i, int j)
{
    int a = mData[i];
    int b = mData[j];
    mData[i] = b;
    mData[j] = a;
}

void ArrayList::add(int x)
{
    insert(mSize, x);
}

void ArrayList::insert(int i, int x)
{
    if (i >= mCapacity)
    {
        mCapacity += mCapacity / 2;
        mData.resize(mCapacity);
    }

    mData[mSize] = x;

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

void ArrayList::clear()
{
    mSize = 0;
    mCapacity = 0;
    mData = std::vector<int>();
}

void ArrayList::print() const
{
    for (int i = 0; i < mSize; ++i)
    {
        std::cout << get(i) << " ";
    }

    std::cout << std::endl;
}