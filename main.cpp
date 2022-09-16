#include <iostream>
#include "algorithms/algorithms.h"
#include "data structures/data structures.h"
#include "utils/utils.h"


int main()
{

    int ordering = REVERSED;
    std::vector<std::vector<int> > tests{{SELECTION_SORT, ordering, ARRAY_LIST},
                                         {INSERTION_SORT, ordering, ARRAY_LIST},
                                         {SELECTION_SORT, ordering, LINKED_LIST},
                                         {INSERTION_SORT, ordering, LINKED_LIST}};

//    Tester::unitTest(tests);

    Tester::benchmark(tests);

    return 0;
}
