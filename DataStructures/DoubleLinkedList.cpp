//
// Created by Chris Howe on 8/1/20.
//

#include "DoubleLinkedList.h"

void DoubleLinkedListNode::setValue(int v)
{
    value_ = v;
}

void DoubleLinkedListNode::setNext(DoubleLinkedListNode *n)
{
    next_ = n;
}

void DoubleLinkedListNode::setPrev(DoubleLinkedListNode *p)
{
    prev_ = p;
}

int DoubleLinkedListNode::getValue()
{
    return value_;
}

DoubleLinkedListNode* DoubleLinkedListNode::getNext()
{
    return next_;
}

DoubleLinkedListNode* DoubleLinkedListNode::getPrev()
{
    return prev_;
}