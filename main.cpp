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
    int data[length] = {8, 12, 15, 1, 4, 10, 400, 3, 1000, 66};

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


    //Linked List Demo
    LinkedList list;

    for (int i = 0; i < length; ++i)
    {
        list.push(data[i]);
    }

    list.print();
    list.append(6403);
    list.print();

    LinkedListNode* temp_node = list.getNode(7);
    printf("Node 7 Value %d\n\n", temp_node->getValue());
    list.insert(temp_node, 360);

    list.print();

    list.removeNode(temp_node);

    list.print();


    /* Insertion Sort Demo
     *
     * */
}