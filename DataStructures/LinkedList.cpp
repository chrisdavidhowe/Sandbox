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

LinkedList::LinkedList():
    sortDirection_(SortDirection::ASCENDING)
{
}

LinkedList::LinkedList(SortDirection direction):
    sortDirection_(direction)
{
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
        return;
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
    else
    {
        end_node = head_->getNext_();

        for (int i = 0; i < length_ - 2; ++i) {
            end_node = end_node->getNext_();
        }

        LinkedListNode *new_node = new LinkedListNode();
        new_node->setNext(nullptr);
        new_node->setValue(value);
        end_node->setNext(new_node);
    }

    length_++;
}

int LinkedList::getLength()
{
    return length_;
}

LinkedListNode* LinkedList::getNode(int index)
{
    LinkedListNode* return_node;
    return_node = head_->getNext_();

    if ((index > length_ - 1) || (index < 0))
    {
        printf("Attempted access outside of linked list range\n");
        return nullptr;
    }

    if (index == 0)
    {
        return head_;
    }
    else if (index == 1)
    {
        return head_->getNext_();
    }
    else
    {
        for (int i = 0; i < length_; ++i)
        {
            if (i == (index - 2))
            {
                return return_node->getNext_();
            }
            return_node = return_node->getNext_();
        }
    }
}

void LinkedList::swap(LinkedListNode *a, LinkedListNode *b)
{
    LinkedListNode* temp;
    int temp_value;

    temp = a->getNext_();
    a->setNext(b->getNext_());
    b->setNext(temp);
    temp_value = a->getValue();
    a->setValue(b->getValue());
    b->setValue(temp_value);
}

void LinkedList::removeNode(LinkedListNode* node)
{
    LinkedListNode* remove_node;
    LinkedListNode* prev_node;
    LinkedListNode* temp_node;

    if (node == head_)
    {
        head_ = head_->getNext_();
    }
    else
    {
        for (int i = 0; i < length_; ++i)
        {
            remove_node = getNode(i);
            if (remove_node == node)
            {
                prev_node = getNode(i - 1);
                prev_node->setNext(remove_node->getNext_());
                remove_node = nullptr;
            }
        }
    }
    length_--;
}

void LinkedList::copy(int* data, int length)
{
    for (int i = 0; i < length; ++i)
    {
        this->push(data[i]);
    }
}

void LinkedList::insertBefore(LinkedListNode *node, int value)
{
    if (node == nullptr)
    {
        printf("Provided Node cannot be NULL\n");
        return;
    }

    if (node == head_)
    {
        LinkedListNode *new_node = new LinkedListNode();
        new_node->setValue(value);
        new_node->setNext(head_);
        head_ = new_node;
        length_++;
    }
    else if (node == head_->getNext_())
    {
        LinkedListNode *new_node = new LinkedListNode();
        new_node->setValue(value);
        new_node->setNext(node->getNext_());
        node->setNext(new_node);
        length_++;
    }
    else
    {
        LinkedListNode* temp;
        temp = head_;

        while (temp->getNext_() != node)
        {
            temp = temp->getNext_();
        }

        LinkedListNode *new_node = new LinkedListNode();
        new_node->setValue(value);
        new_node->setNext(node);
        temp->setNext(new_node);
        length_++;
    }
}

void LinkedList::sortedInsert(int value)
{
    if ( (head_ == nullptr) || (head_->getValue() > value) )
    {
        LinkedListNode* new_node = new LinkedListNode();
        new_node->setValue(value);
        new_node->setNext(head_);
        head_ = new_node;
        length_++;
    }
    else
    {
        LinkedListNode* post = head_;
        LinkedListNode* prev = nullptr;
        bool insert = true;

        while (value > post->getValue())
        {
            if (post->getNext_() == nullptr)
            {
                LinkedListNode* new_node = new LinkedListNode;
                post->setNext(new_node);
                new_node->setValue(value);
                length_++;
                insert = false;
                break;
            }
            else
            {
                prev = post;
                post = post->getNext_();
            }
        }

        if (insert)
        {
            LinkedListNode *new_node = new LinkedListNode;
            new_node->setValue(value);
            prev->setNext(new_node);
            new_node->setNext(post);
            length_++;
        }
    }
}

void LinkedList::print()
{
    LinkedListNode* node;
    node = head_;

    printf("Linked List Length %d\n", length_);

    for (int i = 0; i < length_; ++i)
    {
        printf("Node %d : Value %d \n", i, node->getValue());
        node = node->getNext_();
    }
}

