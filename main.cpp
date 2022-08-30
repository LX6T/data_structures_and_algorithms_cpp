#include <iostream>
#include <ctime>
#include "algorithms/selectionSort.h"
#include "data structures/LinkedList.h"

clock_t start() {
    return clock();
}

void stop(clock_t t) {
    std::cout << "\t\t" << (int)(clock() - t)*0.001 << "s" << std::endl;
}

int main() {

    int data[10] = {9,1,2,6,5,4,9,8,7,6};

    auto* A = new LinkedList(10, data);
    A->printData();
    selectionSort::sortLinkedList(A);
    A->printData();

    std::cout << std::endl;

    auto* LL = new LinkedList(10, data);
    LL->printData();
    selectionSort::sortLinkedList(LL);
    LL->printData();

    return 0;
}

