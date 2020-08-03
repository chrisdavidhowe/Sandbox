//
// Created by Chris Howe on 8/2/20.
//

#include "../DataStructures/LinkedList.h"

void insertionSort(int* data, int length)
{
    LinkedList sorted_list;

    for (int i = 0; i < length; ++i)
    {
        sorted_list.sortedInsert(data[i]);
    }

    sorted_list.print();
};