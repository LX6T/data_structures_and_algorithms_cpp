#include <iostream>
#include <ctime>
#include "utils/BenchMarker.h"
#include "utils/Timer.h"
#include "utils/DataGenerator.h"
#include "algorithms/SelectionSort.h"
#include "data structures/LinkedList.h"


int main() {

    BenchMarker::selectionSortA(1, 100000, 10);
    BenchMarker::selectionSortLL(1, 100000, 10);

    return 0;
}

