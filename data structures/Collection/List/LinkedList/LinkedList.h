//
// Created by alex on 24/08/2022.
//

#include <iostream>
#include "../List.h"
#include "../../Queue/Deque/Deque.h"
#include "Node.h"

#pragma once

class LinkedList : virtual public List, virtual public Deque
{
private:
    int mSize;
    Node* mHead;
    Node* mTail;

public:

    /*  Constructors/Destructors  */
    LinkedList();
    LinkedList(const int* input);
    ~LinkedList();

    /*  Collection methods  */
    int size() const;
    bool isEmpty() const;
    void add(int x);        // addLast()
    void clear();
    void print() const;

    /*  List methods  */
    void insert(int i, int x);
    void remove(int i);
    int get(int i) const;
    void set(int i, int x);
    void swap(int i, int j);

    /*  LinkedList methods  */
    Node* head() const;
    Node* tail() const;
    Node* getNode(int i) const;
    void swap(Node* A, Node* B);
    void remove(Node* node);
    void insertBefore(Node* node, int value);
    void insertAfter(Node* node, int value);

    /*  Deque methods  */
    void addFirst(int x);
    void addLast(int x);
    int removeFirst();
    int removeLast();
    int getFirst() const;
    int getLast() const;

    /*  Queue methods  */
//  void add(int x);        // addLast()            (inherited from Collection)
    int remove();           // removeFirst()
    int peek() const;       // getFirst()

    /*  Stack methods  */
    void push(int x);       // addFirst()
    int pop();              // removeFirst()
//  int peek() const;       // getFirst()           (inherited from Queue)

};


/* ===== CONSTRUCTORS / DESTRUCTORS ===== */

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
        if (mTail == nullptr)
        {
            mHead = new Node(nullptr, nullptr, input[j]);
            mTail = mHead;
        } else
        {
            auto* newEnd = new Node(mTail, nullptr, input[j]);
            mTail->setNext(newEnd);
            mTail = newEnd;
        }
        mSize++;
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


/* ===== COLLECTION METHODS ===== */

int LinkedList::size() const
{
    return mSize;
}

bool LinkedList::isEmpty() const
{
    return mSize == 0;
}

void LinkedList::add(int x)
{
    addLast(x);
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


/* ===== LIST METHODS ===== */

int LinkedList::get(int i) const
{
    return getNode(i)->val();
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


/* ===== LINKED_LIST METHODS ===== */

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


/* ===== DEQUE METHODS ===== */

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
    if (mTail == nullptr)
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

int LinkedList::removeFirst()
{
    int x;
    if (mSize == 0)
    {
        x = -1;
    } else if (mSize == 1)
    {
        x = mHead->val();
        delete mHead;
        mHead = nullptr;
        mTail = nullptr;
    } else
    {
        x = mHead->val();
        Node* newStart = mHead->next();
        newStart->setPrev(nullptr);
        delete mHead;
        mHead = newStart;
    }
    mSize--;
    return x;
}

int LinkedList::removeLast()
{
    int x;
    if (mSize == 0)
    {
        x = -1;
    } else if (mSize == 1)
    {
        x = mHead->val();
        delete mHead;
        mHead = nullptr;
        mTail = nullptr;
    } else
    {
        x = mHead->val();
        Node* newEnd = mTail->prev();
        newEnd->setNext(nullptr);
        delete mTail;
        mTail = newEnd;
    }
    mSize--;
    return x;
}

int LinkedList::getFirst() const
{
    return mHead->val();
}

int LinkedList::getLast() const
{
    return mTail->val();
}


/* ===== QUEUE METHODS ===== */

//  void LinkedList::add(int x)
//  {
//      addLast(x);
//  }

int LinkedList::remove()
{
    return removeFirst();
}

int LinkedList::peek() const
{
    return getFirst();
}


/* ===== STACK METHODS ===== */

void LinkedList::push(int x)
{
    addFirst(x);
}

int LinkedList::pop()
{
    return removeFirst();
}

//  int LinkedList::peek() const
//  {
//      return getFirst();
//  }
