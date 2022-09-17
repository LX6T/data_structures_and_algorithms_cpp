//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "List"
#include "Node.h"

#pragma once

class LinkedList : public List
{
private:
    static const int END = -1;
    Node* mHead;
    Node* mTail;
public:

    LinkedList();
    LinkedList(const int* input);
    ~LinkedList();

    int size() const;
    bool isEmpty() const;

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
        Node* next = current->next();
        delete current;
        current = next;
    }
}


int LinkedList::size() const
{
    return mSize;
}

bool LinkedList::isEmpty() const
{
    return mSize == 0;
}


int LinkedList::get(int i) const
{
    return getNode(i)->val();
}

int LinkedList::getFirst() const
{
    return mHead->val();
}

int LinkedList::getLast() const
{
    return mTail->val();
}

void LinkedList::set(int i, int x)
{
    getNode(i)->setVal(x);
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
        mHead->setPrev(newStart);
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
        mTail->setNext(newEnd);
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
        Node* prev = next->prev();
        auto* insertedNode = new Node(prev, next, x);
        prev->setNext(insertedNode);
        next->setPrev(insertedNode);
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
        Node* prev = target->prev();
        Node* next = target->next();
        delete target;
        prev->setNext(next);
        next->setPrev(prev);
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
        Node* newStart = mHead->next();
        newStart->setPrev(nullptr);
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
        Node* newEnd = mTail->prev();
        newEnd->setNext(nullptr);
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
        Node* next = current->next();
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
        currentNode = currentNode->next();
    }

    return currentNode;
}

void LinkedList::swap(Node* A, Node* B)
{
    int a = A->val();
    int b = B->val();
    A->setVal(b);
    B->setVal(a);
}

void LinkedList::remove(Node* node)
{
    Node* prevNode = node->prev();
    Node* nextNode = node->next();

    if (prevNode != nullptr)
    {
        prevNode->setNext(nextNode);
    } else
    {
        removeFirst();
        return;
    }

    if (nextNode != nullptr)
    {
        nextNode->setPrev(prevNode);
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
    Node* oldPrev = node->prev();
    Node* newPrev = new Node(oldPrev, node, value);
    node->setPrev(newPrev);

    if (oldPrev != nullptr)
    {
        oldPrev->setNext(newPrev);
    } else
    {
        mHead = newPrev;
    }
    mSize++;
}

void LinkedList::insertAfter(Node* node, int value)
{
    Node* oldNext = node->next();
    Node* newNext = new Node(node, oldNext, value);
    node->setNext(newNext);

    if (oldNext != nullptr)
    {
        oldNext->setPrev(newNext);
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
        std::cout << currentNode->val() << " ";
        currentNode = currentNode->next();
    }

    std::cout << std::endl;
}