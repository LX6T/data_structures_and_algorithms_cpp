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


class BenchMarker
{
public:

    static void selectionSortA(int start, int stop, int multiplyStep)
    {
        std::cout << "\n=== Benchmarking SelectionSort on Array ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            Array A = Array(i, DataGenerator::randomIntArray(i, 0, 100));

            {
                Timer timer;
                SelectionSort::sortArray(&A);
            }

        }

    }

    static void selectionSortLL(int start, int stop, int multiplyStep)
    {
        std::cout << "\n=== Benchmarking SelectionSort on LinkedList ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            LinkedList LL = LinkedList(i, DataGenerator::randomIntArray(i, 0, 100));

            {
                Timer timer;
                SelectionSort::sortLinkedList(&LL);
            }

        }

    }

    static void insertionSortA(int start, int stop, int multiplyStep)
    {
        std::cout << "\n=== Benchmarking InsertionSort on Array ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            Array A = Array(i, DataGenerator::randomIntArray(i, 0, 100));

            {
                Timer timer;
                InsertionSort::sortArray(&A);
            }

        }

    }

    static void insertionSortLL(int start, int stop, int multiplyStep)
    {
        std::cout << "\n=== Benchmarking InsertionSort on LinkedList ===" << std::endl;

        for (int i = start; i <= stop; i *= multiplyStep)
        {
            std::cout << i << ": ";
            LinkedList LL = LinkedList(i, DataGenerator::randomIntArray(i, 0, 100));

            {
                Timer timer;
                InsertionSort::sortLinkedList(&LL);
            }

        }

    }

};
