#include <iostream>
#include "algorithms/algorithms.h"
#include "data structures/data structures.h"
#include "utils/utils.h"


int main()
{

    int ordering = RANDOM;
    std::vector<std::vector<int> > tests{{MERGE_SORT, ordering, ARRAY_LIST},
                                         {MERGE_SORT, ordering, LINKED_LIST}};

    Tester::unitTest(tests);

    Tester::benchmark(tests, 1, 10000, 10);

    return 0;
}
