//
// Created by alex on 24/08/2022.
//

#pragma once

class LinkedListNode {
protected:
    LinkedListNode* prev;
    LinkedListNode* next;
    int value;
public:
    LinkedListNode(LinkedListNode* prev, LinkedListNode* next, int value) {
        this->prev = prev;
        this->next = next;
        this->value = value;
    }

    LinkedListNode* getPrevNode() {
        return prev;
    }

    LinkedListNode* getNextNode() {
        return next;
    }

    [[nodiscard]] int getValue() const {
        return value;
    }

    void setNextNode(LinkedListNode* newNext) {
        next = newNext;
    }

    void setPrevNode(LinkedListNode* newPrev) {
        prev = newPrev;
    }

    void setValue(int x) {
        value = x;
    }
};