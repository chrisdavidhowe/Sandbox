//
// Created by Chris Howe on 8/5/20.
//

#pragma once

class StackNode
{
public:
    int value {0};
    StackNode* next;
};

/* LIFO Last In First Out data structure
 * Example : stack of plates :)
 * */


class Stack
{
public:
    void push(int value);
    void pop();
    int  peek();
    int  length();
    void print();
private:
    StackNode* top_ {nullptr};
    int length_ {0};
};