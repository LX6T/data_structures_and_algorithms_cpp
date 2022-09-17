//
// Created by alex on 17/09/2022.
//

#pragma once

#include "../algorithms/algorithms.h"
#include "../data structures/data structures.h"
#include "../utils/utils.h"

struct Tester
{
    static void unitTest(std::vector<std::vector<int> > tests)
    {
        for (std::vector<int> test: tests)
        {
            Algorithm algorithm = (Algorithm) test[0];
            Ordering ordering = (Ordering) test[1];
            Type type = (Type) test[2];

            int* array;

            switch (ordering)
            {
                case RANDOM:
                    array = DataGenerator::randomIntArray(10, 0, 100);
                    break;
                case ORDERED:
                    array = DataGenerator::orderedIntArray(0, 10, 1);
                    break;
                case REVERSED:
                    array = DataGenerator::reversedIntArray(0, 10, 1);
                    break;
            }

            auto A = ArrayList(array);
            auto L = LinkedList(array);

            switch (type)
            {
                case ARRAY_LIST:
                    A.print();
                    switch (algorithm)
                    {
                        case SELECTION_SORT:
                            SelectionSort::sort(A);
                            break;
                        case INSERTION_SORT:
                            InsertionSort::sort(A);
                            break;
                        case MERGE_SORT:
                            MergeSort::sort(A, 0, 9);
                            break;
                        case QUICK_SORT:
                            QuickSort::sort(A, 0, 9);
                            break;
                    }
                    A.print();
                    break;
                case LINKED_LIST:
                    L.print();
                    switch (algorithm)
                    {
                        case SELECTION_SORT:
                            SelectionSort::sort(L);
                            break;
                        case INSERTION_SORT:
                            InsertionSort::sort(L);
                            break;
                        case MERGE_SORT:
                            MergeSort::sort(L, 0, 9);
                            break;
                        case QUICK_SORT:
                            QuickSort::sort(L, 0, 9);
                            break;
                    }
                    L.print();
                    break;
            }
            std::cout << std::endl;
        }
    }

    static void benchmark(std::vector<std::vector<int> > tests, int start, int stop, int multiplyStep)
    {
        for (std::vector<int> test: tests)
        {
            Algorithm algorithm = (Algorithm) test[0];
            Ordering ordering = (Ordering) test[1];
            Type type = (Type) test[2];

            BenchMarker::sort(start, stop, multiplyStep, algorithm, ordering, type);
        }
    }

};
