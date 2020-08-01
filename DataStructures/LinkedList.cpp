//
// Created by Chris Howe on 8/1/20.
//

#include "LinkedList.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

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
        LinkedListNode *new_node = new LinkedListNode();
        new_node->setValue(v);
        new_node->setNext(head_);
        head_ = new_node;
        length_++;
}

void LinkedList::insert(LinkedListNode* prevNode, int value)
{
    if (prevNode == nullptr)
    {
        printf("Provided Node cannot be NULL\n");
        exit(-1);
    }

    LinkedListNode* new_node = new LinkedListNode();
    new_node->setNext(prevNode->getNext_());
    new_node->setValue(value);
    prevNode->setNext(new_node);
    length_++;
}

void LinkedList::append(int value)
{
    LinkedListNode* end_node;

    if (head_->getNext_() == nullptr)
    {

    }
    else {
        end_node = head_->getNext_();

        for (int i = 0; i < length_ - 2; ++i) {
            end_node = end_node->getNext_();
        }

        LinkedListNode *new_node = new LinkedListNode();
        new_node->setNext(nullptr);
        new_node->setValue(value);
        end_node->setNext(new_node);
    }
}

int LinkedList::getLength()
{
    return length_;
}

void LinkedList::print()
{
    LinkedListNode* node;
    node = head_;

    printf("Length %d\n", length_);

    for (int i = 0; i < length_; ++i)
    {
        printf("Node %d : Value %d \n", i, node->getValue());
        node = node->getNext_();
    }
}

