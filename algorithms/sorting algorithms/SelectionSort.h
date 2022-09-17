//
// Created by alex on 24/08/2022.
//

#include "../../data structures/data structures.h"

#pragma once

class SelectionSort
{
public:

    static void sort(ArrayList& A)
    {
        int size = A.size();

        // Searches i times for the next minimum value
        for (int i = 0; i < size; ++i)
        {
            int min = INT8_MAX;
            int minIndex = i;

            // Find the next minimum value
            for (int j = i; j < size; ++j)
            {
                int value = A.get(j);

                if (value < min)
                {
                    min = value;
                    minIndex = j;
                }
            }

            // 0 to i is sorted, i+1 to size-1 is unsorted
            A.swap(i, minIndex);
        }
    }


    static void sort(LinkedList& L)
    {
        int size = L.size();
        Node* currentNode = L.head();

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
            L.swap(currentNode, minNode);

            currentNode = currentNode->getNextNode();
        }
    }

};
