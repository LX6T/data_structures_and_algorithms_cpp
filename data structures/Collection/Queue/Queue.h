//
// Created by alex on 18/09/2022.
//

#pragma once

#include "../Collection.h"


class Queue : virtual public Collection
{
public:

    virtual int peek() const = 0;

    virtual int remove() = 0;

};
