//
// Created by Chris Howe on 7/31/20.
//

#include "main.h"
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

int main (int argc, char *argv[])
{

//    static const int length = 10;
//    int data[length] = {8, 12, 15, 1, 4, 10, 400, 3, 1000, 66};

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
    /*
    LinkedList list;

    for (int i = 0; i < length; ++i)
    {
        list.push(data[i]);
    }

    list.print();
    list.append(6403);
    list.print();

    list.erase();
    list.print();

    LinkedListNode* temp_node = list.getNode(7);
    printf("Node 7 Value %d\n\n", temp_node->getValue());
    list.insert(temp_node, 360);
    list.print();

    // Remove kth from linked list
    // This removes every 3rd node
    int kth = 3;
    for (int i = 0; i < list.getLength(); ++i)
    {
        if ((i % kth) == 0)
        {
            //Don't remove the head
            if (i > 0)
            {
                list.removeNode(list.getNode(i));
            }
        }
    }

    list.print();

    //remove head
    list.removeNode(list.getNode(0));
    list.print();
    */


    /* Insertion Sort Demo */
    //insertionSort(data, length);


    /* Double Linked List */
    /*
    DoubleLinkedList doubleLinkedList;

    for (int i = 0; i < length; ++i)
    {
        doubleLinkedList.push(data[i]);
    }

    doubleLinkedList.print();

    doubleLinkedList.insert(doubleLinkedList.getNode(1), 16148);
    doubleLinkedList.insertBefore(doubleLinkedList.getNode(6), 9999);
    doubleLinkedList.insertBefore(doubleLinkedList.getNode(8), 8898);
    doubleLinkedList.print();
    */

    /* Insertion Sort Double Linked List */
    /*
    DoubleLinkedList doubleLinkedList;
    for (int i = 0; i < length; ++i)
    {
        doubleLinkedList.insertSorted(data[i]);
    }
    doubleLinkedList.print();
    */

    /* Binary Search Tree Demo */
    BinarySearchTree tree;

    static const int length = 6;
    int data[length] = {10, 5, 1, 7, 40, 50};

    tree.construct(data, 0, length - 1, TraversalMode::PREORDER);
    tree.print(tree.getRoot());


}