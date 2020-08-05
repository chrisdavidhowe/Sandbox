//
// Created by Chris Howe on 8/5/20.
//

#pragma once

#include "Utils.h"
#include <cstdio>
#include "Sort/BubbleSort.cpp"
#include "DataStructures/LinkedList.h"
#include "DataStructures/LinkedList.cpp"
#include "Sort/InsertionSort.cpp"
#include "DataStructures/DoubleLinkedList.h"
#include "DataStructures/DoubleLinkedList.cpp"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/BinaryTree.cpp"
#include "DataStructures/Queue.h"
#include "DataStructures/Queue.cpp"
#include "DataStructures/Stack.h"
#include "DataStructures/Stack.cpp"


class Test
{
public:
    Test(int* data, int length);
    void bubbleSortTest();
    void queueTest();
    void stackTest();
    void insertionSortTest();
    void linkedListTest();
    void doubleLinkedListTest();
    void binarySearchTreeTest();
    void redBlackTreeTest();

    void setData(int* data, int length);

private:
    int* data;
    int length {0};
};