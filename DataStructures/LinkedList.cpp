//
// Created by Chris Howe on 8/1/20.
//

#include "LinkedList.h"

void LinkedListNode::setValue(int v)
{
    value_ = v;
}

void LinkedListNode::setNext(LinkedListNode* n)
{
    next_ = n;
}

LinkedListNode* LinkedListNode::getNext_()
{
    return next_;
}

int LinkedListNode::getValue()
{
    return value_;
}
