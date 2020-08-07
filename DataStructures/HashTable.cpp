//
// Created by Chris Howe on 8/5/20.
//

#include "HashTable.h"
#include <memory>
#include <stdlib.h>

void LinkedListString::push(std::string key)
{
    LinkedListStringNode* temp = new LinkedListStringNode(key);
    temp->next_ = head_;
    head_ = temp;
    length_++;
}

bool LinkedListString::find(std::string key)
{
    int found = false;
    LinkedListStringNode* temp = head_;

    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            found = true;
            printf("Found Key : %s\n", key.c_str());
            return found;
        }
        temp = temp->next_;
    }
    printf("Key Not Found! : %s\n", key.c_str());
    return found;
}

HashTable::HashTable(int size):
    size_(size)
{
    table_ = new LinkedListString[size_];
}

HashTable::~HashTable()
{
    delete [] table_;
}

void HashTable::put(std::string key)
{
    //Simple modulo hash
    //int hash = atoi(key.c_str()) % size_;
    //using stdlib
    int hash = std::hash<std::string>{}(key) % size_;
    table_[hash].push(key);
}

bool HashTable::search(std::string key)
{
    int hash = std::hash<std::string>{}(key) % size_;
    table_[hash].find(key);
}

void HashTable::print()
{
    LinkedListStringNode* temp;
    temp = table_[0].head_;

    for (int i = 0; i < size_; ++i)
    {
        while (temp != nullptr)
        {
            printf("Index %d Key %s\n", i, temp->key.c_str());
            temp = temp->next_;
        }
        temp = table_[i].head_;
    }
}
