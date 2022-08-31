#include <iostream>
#include "utils/BenchMarker.h"
#include "utils/Timer.h"
#include "utils/DataGenerator.h"
#include "algorithms/InsertionSort.h"
#include "algorithms/SelectionSort.h"
#include "data structures/LinkedList.h"

enum
{
    RANDOM = 0, ORDERED = 1, REVERSED = 2
};

int main()
{

    Array A = Array(DataGenerator::reversedIntArray(0, 10, 1));
    A.printData();
    InsertionSort::sortArray(&A);
    A.printData();

    LinkedList LL = LinkedList(DataGenerator::randomIntArray(10, 0, 100));
    LL.printData();
    SelectionSort::sortLinkedList(&LL);
    LL.printData();

    int ordering = RANDOM;

    BenchMarker::selectionSortA(1, 10000, 10, ordering);
    BenchMarker::selectionSortLL(1, 10000, 10, ordering);

    BenchMarker::insertionSortA(1, 10000, 10, ordering);
    BenchMarker::insertionSortLL(1, 10000, 10, ordering);

    return 0;
}

