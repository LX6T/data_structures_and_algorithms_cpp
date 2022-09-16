//
// Created by alex on 31/08/2022.
//

#include "../data structures/data structures.h"

#pragma once

class InsertionSort
{
public:

    static void sort(ArrayList& AL)
    {
        int size = AL.size();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {
            int currentValue = AL.get(i);
            int j = i - 1;

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (AL.get(j) > currentValue and j >= 0)
            {
                AL.set(j + 1, AL.get(j));
                --j;
            }
            AL.set(j + 1, currentValue);
        }
    }

    static void sort(LinkedList& LL)
    {
        int size = LL.size();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {

            Node* currentNode = LL.getNode(i);
            int currentValue = currentNode->getValue();

            int j = i - 1;
            Node* sortedNode = currentNode->getPrevNode();

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (sortedNode->getValue() > currentValue and j >= 0)
            {
                currentNode->setValue(sortedNode->getValue());
                --j;

                currentNode = currentNode->getPrevNode();

                if (sortedNode != LL.head())
                {
                    sortedNode = sortedNode->getPrevNode();
                }
            }
            currentNode->setValue(currentValue);
        }
    }

};
