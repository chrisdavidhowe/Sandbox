//
// Created by Chris Howe on 8/2/20.
//

#include "../DataStructures/LinkedList.h"

// Best case complexity O(n)
// Worst case complexity O(n^2)
// Comparison Sort
// Space Complexity 1
// Non-recursive, best for data set sizes 10-50

void insertionSort(int* data, int length)
{
    LinkedList sorted_list;

    for (int i = 0; i < length; ++i)
    {
        sorted_list.sortedInsert(data[i]);
    }

    sorted_list.print();
};