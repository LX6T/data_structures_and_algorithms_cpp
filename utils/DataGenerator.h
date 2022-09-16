//
// Created by alex on 31/08/2022.
//

#include <random>
#include "Enums.h"

#pragma once


class DataGenerator
{
public:

    static int* randomIntArray(int n, int min, int max)
    {
        srand(time(0));
        int* randomArray = new int[n + 1];

        for (int i = 0; i < n; ++i)
        {
            int range = max - min;
            randomArray[i] = (rand() % range) + min;
        }

        randomArray[n] = END;

        return randomArray;
    }

    static int* orderedIntArray(int start, int stop, int step)
    {
        int n = (stop - start) / step;
        int* orderedArray = new int[n + 1];

        for (int i = 0; i < n; ++i)
        {
            orderedArray[i] = (i * step) + start;
        }

        orderedArray[n] = END;

        return orderedArray;
    }

    static int* reversedIntArray(int start, int stop, int step)
    {
        int reverseStart = stop - step;
        int reverseStop = start - step;
        return orderedIntArray(reverseStart, reverseStop, -step);
    }

};
