//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "ListNode.h"
#pragma once

class LinkedList {
private:
    int size;
    ListNode* head;
    ListNode* tail;
public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(int n, const int* input)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int i = 0; i < n; ++i)
        {
            insertBack(input[i]);
        }
    }

    ~LinkedList()
    {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->getNextNode();
            delete current;
            current = next;
        }
    }

    int getData(int i)
    {
        return getNode(i)->getValue();
    }

    ListNode* getStart()
    {
        return head;
    }

    ListNode* getEnd()
    {
        return tail;
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

    void printData()
    {
        ListNode* currentNode = head;

        for (int i = 0; i < size; ++i)
        {
            std::cout << currentNode->getValue() << " ";
            currentNode = currentNode->getNextNode();
        }

        std::cout << std::endl;
    }

    void insertFront(int x)
    {
        if (size == 0)
        {
            head = new ListNode(nullptr, nullptr, x);
            tail = head;
        }
        else
        {
            auto* newStart = new ListNode(nullptr, head, x);
            head->setPrevNode(newStart);
            head = newStart;
        }
        size++;
    }

    void insertBack(int x)
    {
        if (size == 0)
        {
            head = new ListNode(nullptr, nullptr, x);
            tail = head;
        }
        else
        {
            auto* newEnd = new ListNode(tail, nullptr, x);
            tail->setNextNode(newEnd);
            tail = newEnd;
        }
        size++;
    }

    void insertMid(int i, int x)
    {
        if (i <= 0)
        {
            insertFront(x);
        }
        else if (i >= size)
        {
            insertBack(x);
        }
        else
        {
            ListNode* next = getNode(i);
            ListNode* prev = next->getPrevNode();
            auto* insertedNode = new ListNode(prev, next, x);
            prev->setNextNode(insertedNode);
            next->setPrevNode(insertedNode);
            size++;
        }
    }

    void deleteFront()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            ListNode* newStart = head->getNextNode();
            newStart->setPrevNode(nullptr);
            delete head;
            head = newStart;
        }
        size--;
    }

    void deleteBack()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            ListNode* newEnd = tail->getPrevNode();
            newEnd->setNextNode(nullptr);
            delete tail;
            tail = newEnd;
        }
        size--;
    }

    void deleteMid(int i)
    {
        if (i <= 0)
        {
            deleteFront();
        }
        else if (i >= size - 1)
        {
            deleteBack();
        }
        else
        {
            ListNode* target = getNode(i);
            ListNode* prev = target->getPrevNode();
            ListNode* next = target->getNextNode();
            delete target;
            prev->setNextNode(next);
            next->setPrevNode(prev);
            size--;
        }
    }

    ListNode* getNode(int i)
    {
        ListNode* currentNode = head;

        for (int j = 0; j < i; ++j)
        {
            currentNode = currentNode->getNextNode();
        }

        return currentNode;
    }

};
