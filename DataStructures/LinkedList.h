//
// Created by Chris Howe on 8/1/20.
//

#pragma once

#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include "../Utils.h"

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

    LinkedList();
    LinkedList(SortDirection direction);
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

    //Get specific node of list
    LinkedListNode* getNode(int index);

    //Remove a specific node
    void removeNode(LinkedListNode* node);

    //Copy an array of data into a linked list
    void copy(int* data, int length);

    //Swap two linked list nodes
    void swap(LinkedListNode* a, LinkedListNode* b);

    //Insert data in a sorted direction
    void sortedInsert(int value);
    void insertBefore(LinkedListNode* node, int value);

private:
    LinkedListNode* head_ {nullptr};
    int length_ {0};
    const SortDirection sortDirection_;
};