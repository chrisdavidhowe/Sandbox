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