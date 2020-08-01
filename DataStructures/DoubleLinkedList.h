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