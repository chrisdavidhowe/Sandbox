//
// Created by Chris Howe on 7/31/20.
//

#include "main.h"

int main (int argc, char *argv[])
{
    const int length = 10;
    int data[length] = {8, 6, 15, 1, 4, 10, 400, 3, 1000, 66};
    Test tests(data, length);

    //tests.nintendoTests();
        //tests.fixedPointTests();

        /*
    string test = "-1234";
    int out = myAtoi(test);
    printf("%d\n", out);
    int in = -1234;
    string o = myIntToString(in);
    printf("%s\n", o.c_str());
         */
        //tests.bitWiseTests();

        Fibonacci fib;

        fib.calculate(10);

}




//tests.bubbleSortTest();
//tests.linkedListTest();
//tests.insertionSortTest();
//tests.doubleLinkedListTest();
//tests.queueTest();
//tests.stackTest();
//tests.fibonacciTest();
//tests.binarySearchTreeTest();
//tests.arrayTest();
//tests.travellingSalesmanTest();
//tests.hashTableTest();
//tests.quickSortTest();
//tests.print();
//tests.epiTests();
//tests.heapSortTests();
//tests.bitWiseTests();
//tests.nintendoTests();