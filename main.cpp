#include <iostream>
#include "algorithms/algorithms.h"
#include "data structures/data structures.h"
#include "utils/utils.h"


int main()
{
    int n = 100;
    int* input = DataGenerator::randomIntArray(n, 0, 100);

    ArrayList a = ArrayList(input);
    PriorityQueue pq = PriorityQueue(input, '>');

    a.print();

    for (int i = 0; i < n; ++i)
    {
        std::cout << pq.remove() << " ";
    }
    std::cout << std::endl;

//    int ordering = RANDOM;
//    std::vector<std::vector<int> > tests{{QUICK_SORT, ordering, ARRAY_LIST},
//                                         {QUICK_SORT, ordering, LINKED_LIST}};
//
//    Tester::unitTest(tests);
//
//    Tester::benchmark(tests, 1, 10000, 10);

    return 0;
}
