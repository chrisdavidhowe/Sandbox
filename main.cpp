//
// Created by Chris Howe on 7/31/20.
//

#include "main.h"

int main (int argc, char *argv[])
{
    const int length = 10;
    int data[length] = {8, 12, 15, 1, 4, 10, 400, 3, 1000, 66};
    Test tests(data, length);

    //tests.bubbleSortTest();

    //tests.linkedListTest();

    //tests.insertionSortTest();

    //tests.doubleLinkedListTest();

    //tests.queueTest();

    tests.stackTest();
}