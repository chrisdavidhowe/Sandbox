//
// Created by Chris Howe on 8/5/20.
//

#pragma once

#include "LinkedList.h"
#include <string>
#include <memory>

class LinkedListStringNode
{
public:
    LinkedListStringNode(std::string k):
        key(k)
    {}
    std::string key;
    LinkedListStringNode* next_ {nullptr};
};

class LinkedListString
{
public:
    void push(std::string key);
    bool find(std::string key);
    LinkedListStringNode* head_ {nullptr};
    int length_ {0};
};

class HashTable
{
public:
    HashTable(int size);
    ~HashTable();
    void put(std::string key);
    bool search(std::string key);
    void print();

private:
    LinkedListString* table_;
    int size_ {0};
};
