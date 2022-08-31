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
            int j = i - 1;

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (A->getData(j) > currentValue and j >= 0)
            {
                A->setData(j + 1, A->getData(j));
                --j;
            }
            A->setData(j + 1, currentValue);
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

            int j = i - 1;
            ListNode *sortedNode = currentNode->getPrevNode();

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (sortedNode->getValue() > currentValue and j >= 0)
            {
                currentNode->setValue(sortedNode->getValue());
                --j;

                currentNode = currentNode->getPrevNode();

                if (sortedNode != LL->getStart())
                {
                    sortedNode = sortedNode->getPrevNode();
                }
            }
            currentNode->setValue(currentValue);
        }
    }

};
