//
// Created by Chris Howe on 8/5/20.
//

#include "Test.h"

Test::Test(int* d, int l):
    data(d),
    length(l)
{
}

void Test::setData(int* d, int l)
{
    length = l;
    data = d;
}

void Test::bubbleSortTest()
{
    /* Bubble Sort Demo
    * Worst Case O(n^2)
    * Worst sorting algorithm possible
    */
    printf("Bubble Sort Demo \n");

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
}

void Test::queueTest()
{
    printf("Queue Demo \n");

    Queue queue(9);

    for (int i = 0; i < length; ++i)
    {
        queue.enqueue(data[i]);
    }

    queue.print();
    queue.dequeue();
    queue.print();
    queue.dequeue();
    queue.print();
    queue.dequeue();
    queue.print();
}

void Test::linkedListTest()
{
    LinkedList list;

    printf("Linked List Demo \n");

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
}

void Test::insertionSortTest()
{
    printf("Insertion Sort Demo \n");
    insertionSort(data, length);
}

void Test::doubleLinkedListTest()
{
    printf("Double Linked List Demo \n");

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
    doubleLinkedList.erase();

    printf("Double Linked List Insertion Sort Demo \n");

    for (int i = 0; i < length; ++i)
    {
        doubleLinkedList.insertSorted(data[i]);
    }

    doubleLinkedList.print();
}
