//
// Created by Chris Howe on 8/1/20.
//

#pragma once

class LinkedListNode
{
    public:

    void setValue(int v);
    void setNext(LinkedListNode* n);
    int getValue();
    LinkedListNode* getNext_();

    private:
    int value_ {0};
    LinkedListNode* next_;
};

class LinkedList
{
public:
    //Pushes a node on top of list replacing the head
    void push(int value);

    //Insert a node at a specific index
    void insertAtIndex(int value, int index);

    int  getLength()
private:
    LinkedListNode* head_ {nullptr};
};