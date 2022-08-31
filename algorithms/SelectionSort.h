//
// Created by alex on 24/08/2022.
//

#include "../data structures/Array.h"
#include "../data structures/LinkedList.h"
#include "../data structures/ListNode.h"

#pragma once

class SelectionSort
{
public:

    static void sortArray(Array *A)
    {
        int size = A->getSize();

        // Searches i times for the next minimum value
        for (int i = 0; i < size; ++i)
        {
            int min = INT8_MAX;
            int minIndex = i;

            // Find the next minimum value
            for (int j = i; j < size; ++j)
            {
                int value = A->getData(j);

                if (value < min)
                {
                    min = value;
                    minIndex = j;
                }
            }

            // 0 to i is sorted, i+1 to size-1 is unsorted
            A->swapData(i, minIndex);
        }
    }


    static void sortLinkedList(LinkedList *LL)
    {
        int size = LL->getSize();
        ListNode *currentNode = LL->getStart();

        // Searches i times for the next minimum value
        for (int i = 0; i < size; ++i)
        {
            ListNode *scannedNode = currentNode;
            int min = INT8_MAX;
            ListNode *minNode = scannedNode;

            // Find the next minimum value
            for (int j = i; j < size; ++j)
            {
                int value = scannedNode->getValue();

                if (value < min)
                {
                    min = value;
                    minNode = scannedNode;
                }

                scannedNode = scannedNode->getNextNode();
            }

            // 0 to i is sorted, i+1 to size-1 is unsorted
            LL->swapNodeData(currentNode, minNode);

            currentNode = currentNode->getNextNode();
        }
    }

};
