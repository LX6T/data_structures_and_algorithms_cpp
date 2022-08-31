//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "ListNode.h"

#pragma once

class LinkedList
{
private:
    int size;
    ListNode *head;
    ListNode *tail;
public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(int n, const int *input)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int i = 0; i < n; ++i)
        {
            insertTail(input[i]);
        }
    }

    ~LinkedList()
    {
        ListNode *current = head;
        while (current != nullptr)
        {
            ListNode *next = current->getNextNode();
            delete current;
            current = next;
        }
    }

    int getData(int i)
    {
        return getNode(i)->getValue();
    }

    ListNode *getStart()
    {
        return head;
    }

    ListNode *getEnd()
    {
        return tail;
    }

    ListNode *getNode(int i)
    {
        ListNode *currentNode = head;

        for (int j = 0; j < i; ++j)
        {
            currentNode = currentNode->getNextNode();
        }

        return currentNode;
    }

    [[nodiscard]] int getSize() const
    {
        return size;
    }

    void setData(int i, int x)
    {
        getNode(i)->setValue(x);
    }

    void swapData(int i, int j)
    {
        int a = getData(i);
        int b = getData(j);
        setData(i, b);
        setData(j, a);
    }

    void swapNodeData(ListNode *A, ListNode *B)
    {
        int a = A->getValue();
        int b = B->getValue();
        A->setValue(b);
        B->setValue(a);
    }

    void printData()
    {
        ListNode *currentNode = head;

        for (int i = 0; i < size; ++i)
        {
            std::cout << currentNode->getValue() << " ";
            currentNode = currentNode->getNextNode();
        }

        std::cout << std::endl;
    }

    void insertHead(int x)
    {
        if (size == 0)
        {
            head = new ListNode(nullptr, nullptr, x);
            tail = head;
        } else
        {
            auto *newStart = new ListNode(nullptr, head, x);
            head->setPrevNode(newStart);
            head = newStart;
        }
        size++;
    }

    void insertTail(int x)
    {
        if (size == 0)
        {
            head = new ListNode(nullptr, nullptr, x);
            tail = head;
        } else
        {
            auto *newEnd = new ListNode(tail, nullptr, x);
            tail->setNextNode(newEnd);
            tail = newEnd;
        }
        size++;
    }

    void insert(int i, int x)
    {
        if (i <= 0)
        {
            insertHead(x);
        } else if (i >= size)
        {
            insertTail(x);
        } else
        {
            ListNode *next = getNode(i);
            ListNode *prev = next->getPrevNode();
            auto *insertedNode = new ListNode(prev, next, x);
            prev->setNextNode(insertedNode);
            next->setPrevNode(insertedNode);
            size++;
        }
    }

    void insertBefore(ListNode *node, int value)
    {
        ListNode *oldPrev = node->getPrevNode();
        ListNode *newPrev = new ListNode(oldPrev, node, value);
        node->setPrevNode(newPrev);

        if (oldPrev != nullptr)
        {
            oldPrev->setNextNode(newPrev);
        } else
        {
            head = newPrev;
        }
        size++;
    }

    void insertAfter(ListNode *node, int value)
    {
        ListNode *oldNext = node->getNextNode();
        ListNode *newNext = new ListNode(node, oldNext, value);
        node->setNextNode(newNext);

        if (oldNext != nullptr)
        {
            oldNext->setPrevNode(newNext);
        } else
        {
            tail = newNext;
        }
        size++;
    }

    void removeHead()
    {
        if (size == 0)
        {
            return;
        } else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else
        {
            ListNode *newStart = head->getNextNode();
            newStart->setPrevNode(nullptr);
            delete head;
            head = newStart;
        }
        size--;
    }

    void removeTail()
    {
        if (size == 0)
        {
            return;
        } else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else
        {
            ListNode *newEnd = tail->getPrevNode();
            newEnd->setNextNode(nullptr);
            delete tail;
            tail = newEnd;
        }
        size--;
    }

    void remove(int i)
    {
        if (i <= 0)
        {
            removeHead();
        } else if (i >= size - 1)
        {
            removeTail();
        } else
        {
            ListNode *target = getNode(i);
            ListNode *prev = target->getPrevNode();
            ListNode *next = target->getNextNode();
            delete target;
            prev->setNextNode(next);
            next->setPrevNode(prev);
            size--;
        }
    }

    void removeNode(ListNode *node)
    {
        ListNode *prevNode = node->getPrevNode();
        ListNode *nextNode = node->getNextNode();

        if (prevNode != nullptr)
        {
            prevNode->setNextNode(nextNode);
        } else
        {
            removeHead();
            return;
        }

        if (nextNode != nullptr)
        {
            nextNode->setPrevNode(prevNode);
        } else
        {
            removeTail();
            return;
        }

        delete node;
        size--;
    }

};
