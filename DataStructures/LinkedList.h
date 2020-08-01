//
// Created by Chris Howe on 8/1/20.
//

#pragma once

class LinkedList
{
public:
    void add(int value);
    void insert(int index, int value);
    int  length()
    void removeByIndex(int index);
    void removeByKey(int value);

private:

};

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