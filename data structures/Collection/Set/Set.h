//
// Created by alex on 18/09/2022.
//

#pragma once

#include "../Collection.h"

class Set : Collection
{
public:

    virtual bool contains() const = 0;

    virtual void remove() = 0;
    
};
