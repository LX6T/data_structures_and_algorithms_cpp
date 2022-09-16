//
// Created by alex on 24/08/2022.
//

#include "../data structures/data structures.h"

#pragma once

class SelectionSort
{
public:

    static void sort(ArrayList& AL)
    {
        int size = AL.size();

        // Searches i times for the next minimum value
        for (int i = 0; i < size; ++i)
        {
            int min = INT8_MAX;
            int minIndex = i;

            // Find the next minimum value
            for (int j = i; j < size; ++j)
            {
                int value = AL.get(j);

                if (value < min)
                {
                    min = value;
                    minIndex = j;
                }
            }

            // 0 to i is sorted, i+1 to size-1 is unsorted
            AL.swap(i, minIndex);
        }
    }


    static void sort(LinkedList& LL)
    {
        int size = LL.size();
        Node* currentNode = LL.head();

        // Searches i times for the next minimum value
        for (int i = 0; i < size; ++i)
        {
            Node* scannedNode = currentNode;
            int min = INT8_MAX;
            Node* minNode = scannedNode;

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
            LL.swap(currentNode, minNode);

            currentNode = currentNode->getNextNode();
        }
    }

};
