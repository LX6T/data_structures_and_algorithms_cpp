//
// Created by alex on 17/09/2022.
//

#pragma once

#include <algorithm>
#include "../../data structures/data structures.h"

class QuickSort
{
private:

    static int pivot(List& A, int l, int r)
    {
        int m = (l + r) / 2;

        int i = A.get(l);
        int j = A.get(m);
        int k = A.get(r);

        int median;

        if (i >= j and i >= k)
        {
            median = std::max(j, k);
        } else
        {
            median = std::min(std::max(i, j), std::max(i, k));
        }

        if (median == i)
            return l;
        else if (median == j)
            return m;
        else
            return r;
    }

    static int partition(ArrayList& A, int l, int r, int i)
    {
        int lPtr = l;
        int rPtr = r + 1;
        A.swap(i, l);

        int p = A.get(l);

        while (true)
        {
            do
            {
                lPtr++;
            } while (A.get(lPtr) < p);

            do
            {
                rPtr--;
            } while (A.get(rPtr) > p);

            if (lPtr < rPtr)
            {
                A.swap(lPtr, rPtr);
            } else
            {
                A.swap(rPtr, l);
                return rPtr;
            }
        }
    }

    static int partition(LinkedList& L, int l, int r, int i)
    {
        Node* lPtr = L.getNode(l);
        Node* rPtr = L.getNode(r);
        L.swap(i, l);

        int p = lPtr->val();
        int lIndex = l, rIndex = r + 1;

        while (true)
        {
            do
            {
                lPtr = lPtr->next();
                lIndex++;
            } while (lPtr->val() < p);

            do
            {
                if (rIndex <= r)
                    rPtr = rPtr->prev();
                rIndex--;
            } while (rPtr->val() > p);

            if (lIndex < rIndex)
            {
                L.swap(lPtr, rPtr);
            } else
            {
                L.swap(rIndex, l);
                return rIndex;
            }
        }
    }

public:

    static void sort(ArrayList& A, int l, int r)
    {
        if (l < r)
        {
            int i = pivot(A, l, r);
            int j = partition(A, l, r, i);
            sort(A, l, j - 1);
            sort(A, j + 1, r);
        }
    }

    static void sort(LinkedList& L, int l, int r)
    {
        if (l < r)
        {
            int i = pivot(L, l, r);
            int j = partition(L, l, r, i);
            sort(L, l, j - 1);
            sort(L, j + 1, r);
        }
    }

};
