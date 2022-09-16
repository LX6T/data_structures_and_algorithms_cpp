//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "List"
#include "Node.h"
#include "../utils/Enums.h"

#pragma once

class LinkedList : public List
{
private:
    Node* mHead;
    Node* mTail;
public:

    LinkedList();
    LinkedList(const int* input);
    ~LinkedList();

    int size() const;

    int get(int i) const;
    int getFirst() const;
    int getLast() const;
    void set(int i, int x);
    void swap(int i, int j);

    void add(int x);
    void addFirst(int x);
    void addLast(int x);
    void insert(int i, int x);

    void remove(int i);
    void removeFirst();
    void removeLast();
    void clear();

    Node* head() const;
    Node* tail() const;
    Node* getNode(int i) const;
    void swap(Node* A, Node* B);
    void remove(Node* node);

    void insertBefore(Node* node, int value);
    void insertAfter(Node* node, int value);

    void print() const;
};


LinkedList::LinkedList()
{
    mSize = 0;
    mHead = nullptr;
    mTail = nullptr;
}

LinkedList::LinkedList(const int* input)
{
    int i = 0;

    while (input[i] != END)
    {
        ++i;
    }

    mSize = 0;
    mHead = nullptr;
    mTail = nullptr;

    for (int j = 0; j < i; ++j)
    {
        addLast(input[j]);
    }

}

LinkedList::~LinkedList()
{
    Node* current = mHead;
    while (current != nullptr)
    {
        Node* next = current->getNextNode();
        delete current;
        current = next;
    }
}


int LinkedList::size() const
{
    return mSize;
}


int LinkedList::get(int i) const
{
    return getNode(i)->getValue();
}

int LinkedList::getFirst() const
{
    return mHead->getValue();
}

int LinkedList::getLast() const
{
    return mTail->getValue();
}

void LinkedList::set(int i, int x)
{
    getNode(i)->setValue(x);
}

void LinkedList::swap(int i, int j)
{
    int a = get(i);
    int b = get(j);
    set(i, b);
    set(j, a);
}


void LinkedList::add(int x)
{
    insert(mSize, x);
}

void LinkedList::addFirst(int x)
{
    if (mSize == 0)
    {
        mHead = new Node(nullptr, nullptr, x);
        mTail = mHead;
    } else
    {
        auto* newStart = new Node(nullptr, mHead, x);
        mHead->setPrevNode(newStart);
        mHead = newStart;
    }
    mSize++;
}

void LinkedList::addLast(int x)
{
    if (mSize == 0)
    {
        mHead = new Node(nullptr, nullptr, x);
        mTail = mHead;
    } else
    {
        auto* newEnd = new Node(mTail, nullptr, x);
        mTail->setNextNode(newEnd);
        mTail = newEnd;
    }
    mSize++;
}

void LinkedList::insert(int i, int x)
{
    if (i <= 0)
    {
        addFirst(x);
    } else if (i >= mSize)
    {
        addLast(x);
    } else
    {
        Node* next = getNode(i);
        Node* prev = next->getPrevNode();
        auto* insertedNode = new Node(prev, next, x);
        prev->setNextNode(insertedNode);
        next->setPrevNode(insertedNode);
        mSize++;
    }
}


void LinkedList::remove(int i)
{
    if (i <= 0)
    {
        removeFirst();
    } else if (i >= mSize - 1)
    {
        removeLast();
    } else
    {
        Node* target = getNode(i);
        Node* prev = target->getPrevNode();
        Node* next = target->getNextNode();
        delete target;
        prev->setNextNode(next);
        next->setPrevNode(prev);
        mSize--;
    }
}

void LinkedList::removeFirst()
{
    if (mSize == 0)
    {
        return;
    } else if (mSize == 1)
    {
        delete mHead;
        mHead = nullptr;
        mTail = nullptr;
    } else
    {
        Node* newStart = mHead->getNextNode();
        newStart->setPrevNode(nullptr);
        delete mHead;
        mHead = newStart;
    }
    mSize--;
}

void LinkedList::removeLast()
{
    if (mSize == 0)
    {
        return;
    } else if (mSize == 1)
    {
        delete mHead;
        mHead = nullptr;
        mTail = nullptr;
    } else
    {
        Node* newEnd = mTail->getPrevNode();
        newEnd->setNextNode(nullptr);
        delete mTail;
        mTail = newEnd;
    }
    mSize--;
}

void LinkedList::clear()
{
    Node* current = mHead;
    while (current != nullptr)
    {
        Node* next = current->getNextNode();
        delete current;
        current = next;
    }
    mSize = 0;
    mHead = nullptr;
    mTail = nullptr;
}


Node* LinkedList::head() const
{
    return mHead;
}

Node* LinkedList::tail() const
{
    return mTail;
}

Node* LinkedList::getNode(int i) const
{
    Node* currentNode = mHead;

    for (int j = 0; j < i; ++j)
    {
        currentNode = currentNode->getNextNode();
    }

    return currentNode;
}

void LinkedList::swap(Node* A, Node* B)
{
    int a = A->getValue();
    int b = B->getValue();
    A->setValue(b);
    B->setValue(a);
}

void LinkedList::remove(Node* node)
{
    Node* prevNode = node->getPrevNode();
    Node* nextNode = node->getNextNode();

    if (prevNode != nullptr)
    {
        prevNode->setNextNode(nextNode);
    } else
    {
        removeFirst();
        return;
    }

    if (nextNode != nullptr)
    {
        nextNode->setPrevNode(prevNode);
    } else
    {
        removeLast();
        return;
    }

    delete node;
    mSize--;
}


void LinkedList::insertBefore(Node* node, int value)
{
    Node* oldPrev = node->getPrevNode();
    Node* newPrev = new Node(oldPrev, node, value);
    node->setPrevNode(newPrev);

    if (oldPrev != nullptr)
    {
        oldPrev->setNextNode(newPrev);
    } else
    {
        mHead = newPrev;
    }
    mSize++;
}

void LinkedList::insertAfter(Node* node, int value)
{
    Node* oldNext = node->getNextNode();
    Node* newNext = new Node(node, oldNext, value);
    node->setNextNode(newNext);

    if (oldNext != nullptr)
    {
        oldNext->setPrevNode(newNext);
    } else
    {
        mTail = newNext;
    }
    mSize++;
}


void LinkedList::print() const
{
    Node* currentNode = mHead;

    for (int i = 0; i < mSize; ++i)
    {
        std::cout << currentNode->getValue() << " ";
        currentNode = currentNode->getNextNode();
    }

    std::cout << std::endl;
}