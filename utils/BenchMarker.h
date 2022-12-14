//
// Created by alex on 31/08/2022.
//

#include "DataGenerator.h"
#include "Timer.h"
#include "Enums.h"
#include "../data structures/data structures.h"
#include "../algorithms/algorithms.h"

#pragma once

class BenchMarker
{
private:

    inline static const std::vector<std::string> scAlgorithms{"SelectionSort", "InsertionSort", "MergeSort",
                                                              "QuickSort"};
    inline static const std::vector<std::string> scOrderings{"Random", "Ordered", "Reversed"};
    inline static const std::vector<std::string> scTypes{"ArrayList", "LinkedList"};

    static const int* generateData(int i, Ordering ordering)
    {
        const int* data;

        switch (ordering)
        {
            case RANDOM:
                data = DataGenerator::randomIntArray(i, 0, 100);
                break;
            case ORDERED:
                data = DataGenerator::orderedIntArray(0, i, 1);
                break;
            case REVERSED:
                data = DataGenerator::orderedIntArray(0, i, 1);
                break;
        }

        return data;
    }

    static const void logMessage(Algorithm a, Ordering o, Type t)
    {
        std::cout << "\n=== Benchmarking " << scAlgorithms[a] << " on " << scOrderings[o] << " " << scTypes[t] << " ==="
                  << std::endl;
    }


public:

    static void sort(int start, int stop, int multiplyStep, Algorithm algorithm, Ordering ordering, Type type)
    {
        logMessage(algorithm, ordering, type);

        std::string space = "        ";

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            space.pop_back();
            std::cout << "n = " << i << space;

            ArrayList A = ArrayList(generateData(i, ordering));

            {
                Timer timer;

                switch (algorithm)
                {
                    case SELECTION_SORT:
                        SelectionSort::sort(A);
                        break;
                    case INSERTION_SORT:
                        InsertionSort::sort(A);
                        break;
                    case MERGE_SORT:
                        MergeSort::sort(A, 0, i - 1);
                        break;
                    case QUICK_SORT:
                        QuickSort::sort(A, 0, i - 1);
                        break;
                }
            }
        }
    }
};
