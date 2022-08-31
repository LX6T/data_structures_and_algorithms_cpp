//
// Created by alex on 31/08/2022.
//

#include "DataGenerator.h"
#include "Timer.h"
#include "../data structures/Array.h"
#include "../data structures/LinkedList.h"
#include "../algorithms/SelectionSort.h"
#include "../algorithms/InsertionSort.h"

#pragma once

//enum
//{
//    RANDOM = 0, ORDERED = 1, REVERSED = 2
//};

class BenchMarker
{
private:
    static const int *generateData(int i, int ordering)
    {
        const int *data;

        switch (ordering)
        {
            case 0:
                data = DataGenerator::randomIntArray(i, 0, 100);
                break;
            case 1:
                data = DataGenerator::orderedIntArray(0, i, 1);
                break;
            case 2:
                data = DataGenerator::orderedIntArray(0, i, 1);
                break;
        }

        return data;
    }

public:

    static void selectionSortA(int start, int stop, int multiplyStep, int ordering)
    {
        std::cout << "\n=== Benchmarking SelectionSort on Random Array ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";

            Array A = Array(generateData(i, ordering));

            {
                Timer timer;
                SelectionSort::sortArray(&A);
            }

        }

    }

    static void selectionSortLL(int start, int stop, int multiplyStep, int ordering)
    {
        std::cout << "\n=== Benchmarking SelectionSort on Random LinkedList ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            LinkedList LL = LinkedList(generateData(i, ordering));

            {
                Timer timer;
                SelectionSort::sortLinkedList(&LL);
            }

        }

    }

    static void insertionSortA(int start, int stop, int multiplyStep, int ordering)
    {
        std::cout << "\n=== Benchmarking InsertionSort on Random Array ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            Array A = Array(generateData(i, ordering));

            {
                Timer timer;
                InsertionSort::sortArray(&A);
            }

        }

    }

    static void insertionSortLL(int start, int stop, int multiplyStep, int ordering)
    {
        std::cout << "\n=== Benchmarking InsertionSort on Random LinkedList ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            LinkedList LL = LinkedList(generateData(i, ordering));

            {
                Timer timer;
                InsertionSort::sortLinkedList(&LL);
            }

        }

    }

};
