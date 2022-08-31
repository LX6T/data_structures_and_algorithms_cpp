//
// Created by alex on 31/08/2022.
//

#include "../data structures/Array.h"

#pragma once


class InsertionSort
{
public:

    static void sortArray(Array *A)
    {
        int size = A->getSize();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {
            int currentValue = A->getData(i);

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            for (int j = i - 1; j >= 0; --j)
            {
                if (A->getData(j) <= currentValue)
                {
                    A->remove(i);
                    A->insert(j + 1, currentValue);
                    break;
                }

                // Inserts at start if no smaller value is found
                if (j == 0)
                {
                    A->remove(i);
                    A->insertFront(currentValue);
                }
            }
        }
    }

    static void sortLinkedList(LinkedList *LL)
    {
        int size = LL->getSize();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {
            ListNode *currentNode = LL->getNode(i);
            int currentValue = currentNode->getValue();

            ListNode *nextSortedNode = LL->getNode(i - 1);

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            for (int j = i - 1; j >= 0; --j)
            {
                if (nextSortedNode->getValue() <= currentValue)
                {
                    LL->removeNode(currentNode);
                    LL->insertAfter(nextSortedNode, currentValue);
                    break;
                }

                // Inserts at start if no smaller value is found
                if (j == 0)
                {
                    LL->removeNode(currentNode);
                    LL->insertHead(currentValue);
                }

                nextSortedNode = nextSortedNode->getPrevNode();
            }
        }
    }

};
