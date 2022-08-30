//
// Created by alex on 24/08/2022.
//

#pragma once

class ListNode {
private:
    ListNode* prev;
    ListNode* next;
    int value;
public:

    // Each node stores a value, plus pointers to the next and previous nodes
    ListNode(ListNode* prev, ListNode* next, int value)
    {
        this->prev = prev;
        this->next = next;
        this->value = value;
    }

    ListNode* getPrevNode()
    {
        return prev;
    }

    ListNode* getNextNode()
    {
        return next;
    }

    [[nodiscard]] int getValue() const
    {
        return value;
    }

    void setNextNode(ListNode* newNext)
    {
        next = newNext;
    }

    void setPrevNode(ListNode* newPrev)
    {
        prev = newPrev;
    }

    void setValue(int x)
    {
        value = x;
    }

};