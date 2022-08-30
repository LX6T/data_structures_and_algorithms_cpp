#include <iostream>
#include <ctime>
#include "utils/Timer.h"
#include "utils/DataGenerator.h"
#include "algorithms/selectionSort.h"
#include "data structures/LinkedList.h"


int main() {

    int size = 10000;
    int* data = DataGenerator::randomIntArray(size, 0, 100);

    {
        Timer timer;
    }

    std::cout << std::endl;

    {
        Timer timer;
        auto* A = new Array(size, data);
//        A->printData();
        selectionSort::sortArray(A);
//        A->printData();
    }

    std::cout << std::endl;

    {
        Timer timer;
        auto* LL = new LinkedList(size, data);
//        LL->printData();
        selectionSort::sortLinkedList(LL);
//        LL->printData();
    }

    return 0;
}

