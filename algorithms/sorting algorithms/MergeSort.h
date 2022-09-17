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
        int i = l, j = s, k = 0;

        int t[r - l + 1];

        while (i < s and j <= r)
        {
            if (A.get(i) <= A.get(j))
            {
                t[k] = A.get(i);
                k++, i++;
            } else
            {
                t[k] = A.get(j);
                k++, j++;
            }
        }
        while (i < s)
        {
            t[k] = A.get(i);
            k++, i++;
        }
        while (j <= r)
        {
            t[k] = A.get(j);
            k++, j++;
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

        while (i != sNode and j != rNode->next())
        {
            if (i->val() <= j->val())
            {
                t[k] = i->val();
                k++, i = i->next();
            } else
            {
                t[k] = j->val();
                k++, j = j->next();
            }
        }
        while (i != sNode)
        {
            t[k] = i->val();
            k++, i = i->next();
        }
        while (j != rNode->next())
        {
            t[k] = j->val();
            k++, j = j->next();
        }

        Node* m = L.getNode(l);
        k = 0;
        while (m != rNode->next())
        {
            m->setVal(t[k]);
            k++, m = m->next();
        }
    }

public:

    static void sort(ArrayList& A, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            sort(A, l, m);
            sort(A, m + 1, r);
            merge(A, l, r, m + 1);
        }
    }


    static void sort(LinkedList& L, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            sort(L, l, m);
            sort(L, m + 1, r);
            merge(L, l, r, m + 1);
        }
    }

};
