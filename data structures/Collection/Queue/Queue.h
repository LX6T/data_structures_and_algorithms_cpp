//
// Created by alex on 18/09/2022.
//

#pragma once

#include "../Collection.h"


class Queue : virtual public Collection
{
public:

    /*  Queue Methods  */

//  virtual void add(int x) = 0;        (inherited from Collection)

    virtual int remove() = 0;

    virtual int peek() const = 0;

};
