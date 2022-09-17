//
// Created by alex on 24/08/2022.
//

#pragma once

class Node
{
private:
    Node* prev;
    Node* next;
    int value;
public:

    // Each node stores a value, plus pointers to the next and previous nodes
    Node(Node* prev, Node* next, int value)
    {
        this->prev = prev;
        this->next = next;
        this->value = value;
    }

    Node* getPrevNode()
    {
        return prev;
    }

    Node* getNextNode()
    {
        return next;
    }

    int getValue() const
    {
        return value;
    }

    void setNextNode(Node* newNext)
    {
        next = newNext;
    }

    void setPrevNode(Node* newPrev)
    {
        prev = newPrev;
    }

    void setValue(int x)
    {
        value = x;
    }

};