//
// Created by Chris Howe on 8/1/20.
//

#pragma once

#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

class LinkedListNode
{
    public:

    void setValue(int v);
    void setNext(LinkedListNode* n);
    int  getValue();
    LinkedListNode* getNext_();

    private:
    int value_ {0};
    LinkedListNode* next_ {nullptr};
};

class LinkedList
{
public:
    //Pushes a node on top of the list replacing the head
    void push(int value);

    //Inserts a node after the provided node
    void insert(LinkedListNode* node, int value);

    //Adds a node to the end of the current list
    void append(int value);

    //Return length
    int  getLength();

    //Print entire list
    void print();

private:
    LinkedListNode* head_ {nullptr};
    int length_ {0};
};