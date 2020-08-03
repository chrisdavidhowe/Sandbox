//
// Created by Chris Howe on 8/1/20.
//

#include "DoubleLinkedList.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

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

void DoubleLinkedList::push(int value)
{
    DoubleLinkedListNode* new_node = new DoubleLinkedListNode();
    new_node->setValue(value);
    new_node->setNext(head_);
    head_->setPrev(new_node);
    head_ = new_node;
    length_++;
}

void DoubleLinkedList::print()
{
    DoubleLinkedListNode* node;
    node = head_;

    printf("Double Linked List Length %d\n", length_);
    printf("Print Forward\n");

    for (int i = 0; i < length_; ++i)
    {
        printf("Node %d : Value %d \n", i, node->getValue());
        node = node->getNext();
    }

    printf("Print Backward\n");
    node = node->getPrev();

    for (int i = length_; i > 0; --i)
    {
        printf("Node %d : Value %d \n", i, node->getValue());
        node = node->getPrev();
    }
}