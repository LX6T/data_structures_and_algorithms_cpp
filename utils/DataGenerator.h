//
// Created by alex on 31/08/2022.
//

#include <random>
#pragma once


class DataGenerator {
public:

    static int* randomIntArray(int n, int min, int max)
    {
        srand(time(0));
        int* randomArray = new int[n];

        for (int i = 0; i < n; ++i)
        {
            int range = max - min;
            randomArray[i] = (rand() % range) + min;
        }

        return randomArray;
    }

};
