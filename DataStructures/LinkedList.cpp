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

void LinkedList::push(int v)
{
    // Head of the list doesn't exist yet so create it
    if (head_ == nullptr)
    {
        LinkedListNode* new_node = new LinkedListNode();
        new_node->setValue(v);
        new_node->setNext(nullptr);
        head_ = new_node;
    }
    else
    // Head exists so swap and push the head down the list
    {
        LinkedListNode* new_node = new LinkedListNode();
        new_node->setValue(v);
        new_node->setNext(head_);
        head_ = new_node;
    }
}
