//
// Created by Chris Howe on 8/5/20.
//

#include "Stack.h"


void Stack::push(int value)
{
    StackNode* new_node = new StackNode;
    new_node->value = value;
    new_node->next = top_;
    top_ = new_node;
    length_++;
}

void Stack::pop()
{
    top_ = top_->next;
    length_--;
}

int Stack::peek()
{
    return top_->value;
}

int Stack::length()
{
    return length_;s
}

void Stack::print()
{
    StackNode* tmp = top_;
    printf("\nStack Length : %d\n", length());
    printf("Stack Top : %d\n", top_->value);
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
        printf("Stack Data : %d\n", tmp->value);
    }
}
