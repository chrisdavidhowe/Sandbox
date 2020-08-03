//
// Created by Chris Howe on 8/1/20.
//

#pragma once

class DoubleLinkedListNode
{
public:
    int getValue();
    DoubleLinkedListNode* getPrev();
    DoubleLinkedListNode* getNext();
    void setValue(int v);
    void setNext(DoubleLinkedListNode* n);
    void setPrev(DoubleLinkedListNode* p);
private:
    int value_ {0};
    DoubleLinkedListNode* prev_ {nullptr};
    DoubleLinkedListNode* next_ {nullptr};
};

class DoubleLinkedList
{
public:
    //Pushes a node on top of the list replacing the head
    void push(int value);

    //Inserts a node after the provided node
    void insert(DoubleLinkedListNode* node, int value);

    //Inserts a node before the given node
    void insertBefore(DoubleLinkedListNode* node, int value);

    //Insert Sorted
    void insertSorted(int value);

    //Adds a node to the end of the current list
    void append(int value);

    //Return length
    int getLength();

    //Print entire list
    void print();

    //Get specific node of list
    DoubleLinkedListNode* getNode(int index);

    //Remove a specific node
    void removeNode(DoubleLinkedList* node);

private:
    DoubleLinkedListNode* head_ {nullptr};
    int length_ {0};
};