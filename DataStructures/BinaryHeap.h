//
// Created by Chris Howe on 8/6/20.
//

#pragma once
#include "BinaryTree.h"
#include <vector>

class BinaryHeapNode
{
public:
    BinaryHeapNode(int v, BinaryHeapNode* p) : value(v), parent(p)  {};
    int value;
    BinaryHeapNode* left    {nullptr};
    BinaryHeapNode* right   {nullptr};
    BinaryHeapNode* parent  {nullptr};
};

enum CHILD
{
    LEFT = 0,
    RIGHT = 1
};

class BinaryHeap
{

public:
    void construct(int* data, int length);
    void heapify(std::vector<int>& heapTree, int index);
    void print();
private:
    int* data_;
    std::vector<int> heapTree_;
};
