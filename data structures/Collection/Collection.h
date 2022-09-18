//
// Created by alex on 18/09/2022.
//

#pragma once


class Collection
{
public:

    virtual int size() const = 0;

    virtual bool isEmpty() const = 0;

    virtual void add(int x) = 0;

    virtual void clear() = 0;

};