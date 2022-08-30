//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "LinkedListNode.h"
#pragma once

class LinkedList {
private:
    int size;
    LinkedListNode* start;
    LinkedListNode* end;
public:

    LinkedList() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    LinkedList(int n, const int* input) {
        start = nullptr;
        end = nullptr;
        size = 0;
        for (int i = 0; i < n; ++i) {
            insertBack(input[i]);
        }
    }

    ~LinkedList() {
        delete start;
        delete end;
    }

    int getData(int i) {
        return getNode(i)->getValue();
    }

    LinkedListNode* getStart() {
        return start;
    }

    LinkedListNode* getEnd() {
        return end;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    void setData(int i, int x) {
        getNode(i)->setValue(x);
    }

    void swapData(int i, int j) {
        int a = getData(i);
        int b = getData(j);
        setData(i, b);
        setData(j, a);
    }

    void printData() {
        LinkedListNode* currentNode = start;
        for (int i = 0; i < size; ++i) {
            std::cout << currentNode->getValue() << " ";
            currentNode = currentNode->getNextNode();
        }
        std::cout << std::endl;
    }

    void insertFront(int x) {
        if (size == 0) {
            start = new LinkedListNode(nullptr, nullptr, x);
            end = start;
        } else {
            auto* newStart = new LinkedListNode(nullptr, start, x);
            start->setPrevNode(newStart);
            start = newStart;
        }
        size++;
    }

    void insertBack(int x) {
        if (size == 0) {
            start = new LinkedListNode(nullptr, nullptr, x);
            end = start;
        } else {
            auto* newEnd = new LinkedListNode(end, nullptr, x);
            end->setNextNode(newEnd);
            end = newEnd;
        }
        size++;
    }

    void insertMid(int i, int x) {
        if (i <= 0) {
            insertFront(x);
        } else if (i >= size) {
            insertBack(x);
        } else {
            LinkedListNode* next = getNode(i);
            LinkedListNode* prev = next->getPrevNode();
            auto* insertedNode = new LinkedListNode(prev, next, x);
            prev->setNextNode(insertedNode);
            next->setPrevNode(insertedNode);
            size++;
        }
    }

    void deleteFront() {
        if (size == 0) {
            return;
        } else if (size == 1) {
            delete start;
            start = nullptr;
            end = nullptr;
        } else {
            LinkedListNode* newStart = start->getNextNode();
            newStart->setPrevNode(nullptr);
            delete start;
            start = newStart;
        }
        size--;
    }

    void deleteBack() {
        if (size == 0) {
            return;
        } else if (size == 1) {
            delete start;
            start = nullptr;
            end = nullptr;
        } else {
            LinkedListNode* newEnd = end->getPrevNode();
            newEnd->setNextNode(nullptr);
            delete end;
            end = newEnd;
        }
        size--;
    }

    void deleteMid(int i) {
        if (i <= 0) {
            deleteFront();
        } else if (i >= size - 1) {
            deleteBack();
        } else {
            LinkedListNode* target = getNode(i);
            LinkedListNode* prev = target->getPrevNode();
            LinkedListNode* next = target->getNextNode();
            delete target;
            prev->setNextNode(next);
            next->setPrevNode(prev);
            size--;
        }
    }

    LinkedListNode* getNode(int i) {
        LinkedListNode* currentNode = start;
        for (int j = 0; j < i; ++j) {
            currentNode = currentNode->getNextNode();
        }
        return currentNode;
    }
};
