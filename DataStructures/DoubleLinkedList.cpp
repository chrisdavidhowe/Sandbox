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

void DoubleLinkedList::insertBefore(DoubleLinkedListNode* node, int value)
{
    DoubleLinkedListNode* new_node = new DoubleLinkedListNode();
    new_node->setValue(value);
    new_node->setPrev(node->getPrev());
    new_node->setNext(node);
    node->getPrev()->setNext(new_node);
    node->setPrev(new_node);
    length_++;
}

void DoubleLinkedList::insert(DoubleLinkedListNode *node, int value)
{
    DoubleLinkedListNode* new_node = new DoubleLinkedListNode();
    new_node->setValue(value);
    new_node->setPrev(node);
    new_node->setNext(node->getNext());
    node->getNext()->setPrev(new_node);
    node->setNext(new_node);
    length_++;
}

DoubleLinkedListNode* DoubleLinkedList::getNode(int index)
{
    DoubleLinkedListNode* return_node = head_;
    for (int i = 0; i < length_; ++i)
    {
        if (i == index)
        {
            return return_node;
        }
        else
        {
            return_node = return_node->getNext();
        }
    }
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

void DoubleLinkedList::insertSorted(int value)
{
    if (head_ == nullptr)
    {
        push(value);
    }
    else if (head_->getNext() == nullptr)
    {
        if (value > head_->getValue())
        {
            DoubleLinkedListNode* new_node = new DoubleLinkedListNode();
            new_node->setValue(value);
            head_->setNext(new_node);
            length_++;
        }
        else
        {
            push(value);
        }
    }
    else
    {
        DoubleLinkedListNode* temp_node = head_;
        bool insert = false;

        while (value > temp_node->getValue() )
        {
            temp_node = temp_node->getNext();

            if (temp_node->getNext() == nullptr)
            {
                DoubleLinkedListNode* new_node = new DoubleLinkedListNode();
                new_node->setValue(value);
                new_node->setPrev(temp_node);
                temp_node->setNext(new_node);
                insert = false;
                length_++;
                break;
            }
        }

        if (insert)
        {
            insertBefore(temp_node, value);
        }
    }
}