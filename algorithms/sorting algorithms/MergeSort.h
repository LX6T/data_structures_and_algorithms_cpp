//
// Created by alex on 31/08/2022.
//

#include "../../data structures/data structures.h"

#pragma once


class MergeSort
{
private:
    static void merge(ArrayList& A, int l, int r, int s)
    {
        int i = l;
        int j = s;
        int k = 0;

        int t[r - l + 1];

        while (i < s and j <= r)
        {
            if (A.get(i) <= A.get(j))
            {
                t[k] = A.get(i);
                k++;
                i++;
            } else
            {
                t[k] = A.get(j);
                k++;
                j++;
            }
        }
        while (i < s)
        {
            t[k] = A.get(i);
            k++;
            i++;
        }
        while (j <= r)
        {
            t[k] = A.get(j);
            k++;
            j++;
        }

        for (int m = l; m <= r; ++m)
        {
            A.set(m, t[m - l]);
        }
    }

    static void merge(LinkedList& L, int l, int r, int s)
    {
        Node* lNode = L.getNode(l);
        Node* rNode = L.getNode(r);
        Node* sNode = L.getNode(s);

        Node* i = lNode;
        Node* j = sNode;
        int k = 0;

        int t[r - l + 1];

        while (i != sNode and j != rNode->getNextNode())
        {
            if (i->getValue() <= j->getValue())
            {
                t[k] = i->getValue();
                k++;
                i = i->getNextNode();
            } else
            {
                t[k] = j->getValue();
                k++;
                j = j->getNextNode();
            }
        }
        while (i != sNode)
        {
            t[k] = i->getValue();
            k++;
            i = i->getNextNode();
        }
        while (j != rNode->getNextNode())
        {
            t[k] = j->getValue();
            k++;
            j = j->getNextNode();
        }

        Node* m = L.getNode(l);
        k = 0;
        while (m != rNode->getNextNode())
        {
            m->setValue(t[k]);
            m = m->getNextNode();
            k++;
        }
    }

public:

    static void sort(ArrayList& A, int i, int j)
    {
        if (i < j)
        {
            int m = (i + j) / 2;
            sort(A, i, m);
            sort(A, m + 1, j);
            merge(A, i, j, m + 1);
        }
    }


    static void sort(LinkedList& L, int i, int j)
    {
        if (i < j)
        {
            int m = (i + j) / 2;
            sort(L, i, m);
            sort(L, m + 1, j);
            merge(L, i, j, m + 1);
        }
    }

};
