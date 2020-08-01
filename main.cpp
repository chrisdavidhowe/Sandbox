//
// Created by Chris Howe on 7/31/20.
//

#include "main.h"
#include "Utils.h"
#include <cstdio>
#include "Sort/BubbleSort.cpp"
#include "DataStructures/LinkedList.h"
#include "DataStructures/LinkedList.cpp"

int main (int argc, char *argv[])
{

    static const int length = 10;
    int data[length] = {8, 12, 15, 1, 4, 10, 400, 3, 1000};

    /* Bubble Sort Demo
     * Worst Case O(n^2)
     * Worst sorting algorithm possible
     */

    /*
    printf(" Bubble Sort Original Data \n");

    for (int i = 0; i < length; ++i)
    {
        printf("%d\t", data[i]);
    }

    bubbleSort(&data[0], length);

    printf("\nBubble Sort Sorted Data \n");
    for (int i = 0; i < length; ++i)
    {
        printf("%d\t", data[i]);
    }
    */


    LinkedList list;

    for (int i = 0; i < length; ++i)
    {
        list.push(data[i]);
    }

    list.print();

    /* Insertion Sort Demo
     *
     * */
}