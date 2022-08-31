#include <iostream>
#include "utils/BenchMarker.h"
#include "utils/Timer.h"
#include "utils/DataGenerator.h"
#include "algorithms/InsertionSort.h"
#include "algorithms/SelectionSort.h"
#include "data structures/LinkedList.h"


int main()
{

//    Array A = Array(10, DataGenerator::randomIntArray(10, 0, 100));
//    SelectionSort::sortArray(&A);
//    A.printData();
//
//    LinkedList LL = LinkedList(10, DataGenerator::randomIntArray(10, 0, 100));
//    SelectionSort::sortLinkedList(&LL);
//    LL.printData();

    BenchMarker::selectionSortA(1, 10000, 10);
    BenchMarker::selectionSortLL(1, 10000, 10);

    BenchMarker::insertionSortA(1, 10000, 10);
    BenchMarker::insertionSortLL(1, 10000, 10);

    return 0;
}

