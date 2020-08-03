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
    DoubleLinkedListNode* prev_;
    DoubleLinkedListNode* next_;
};

class DoubleLinkedList
{
public:
    //Pushes a node on top of the list replacing the head
    void push(int value);

    //Inserts a node after the provided node
    void insert(DoubleLinkedList* node, int value);

    //Adds a node to the end of the current list
    void append(int value);

    //Return length
    int  getLength();

    //Print entire list
    void print();

    //Get specific node of list
    DoubleLinkedList* getNode(int index);

    //Remove a specific node
    void removeNode(DoubleLinkedList* node);

private:
    DoubleLinkedListNode* head_;
    int length_ {0};
};