#include <iostream>
#include <ctime>
#include "utils/Timer.h"
#include "algorithms/selectionSort.h"
#include "data structures/LinkedList.h"


int main() {

    int data[10] = {9,1,2,6,5,4,9,8,7,6};

    {
        Timer timer;
    }

    {
        Timer timer;
        auto* A = new Array(10, data);
        A->printData();
        selectionSort::sortArray(A);
        A->printData();
    }

    std::cout << std::endl;

    {
        Timer timer;
        auto* LL = new LinkedList(10, data);
        LL->printData();
        selectionSort::sortLinkedList(LL);
        LL->printData();
    }

    return 0;
}

