//
// Created by alex on 31/08/2022.
//

#include "../../data structures/data structures.h"

#pragma once

class InsertionSort
{
public:

    static void sort(ArrayList& A)
    {
        int size = A.size();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {
            int currentValue = A.get(i);
            int j = i - 1;

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (A.get(j) > currentValue and j >= 0)
            {
                A.set(j + 1, A.get(j));
                --j;
            }
            A.set(j + 1, currentValue);
        }
    }

    static void sort(LinkedList& L)
    {
        int size = L.size();

        // Inserts i times into the sorted sublist
        for (int i = 1; i < size; ++i)
        {

            Node* currentNode = L.getNode(i);
            int currentValue = currentNode->getValue();

            int j = i - 1;
            Node* sortedNode = currentNode->getPrevNode();

            // Find the last item in the sorted sublist not exceeding currentValue and insert after it
            while (sortedNode->getValue() > currentValue and j >= 0)
            {
                currentNode->setValue(sortedNode->getValue());
                --j;

                currentNode = currentNode->getPrevNode();

                if (sortedNode != L.head())
                {
                    sortedNode = sortedNode->getPrevNode();
                }
            }
            currentNode->setValue(currentValue);
        }
    }

};
