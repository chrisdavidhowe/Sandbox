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

void Test::arrayTest()
{
    int sum = 9;
    twoSum(data, length, sum);
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

    for (int i = 0; i < 12; ++i)
    {
        queue.enqueue(data[i]);
    }

//    queue.print();
//    queue.dequeue();
//    queue.print();
//    queue.dequeue();
//    queue.print();
//    queue.dequeue();
//    queue.print();
}

void Test::stackTest()
{
    Stack stack;

    for (int i = 0; i < length; ++i)
    {
        stack.push(data[i]);
    }

    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();

}

void Test::fibonacciTest()
{
    Fibonacci fib;

    int out = fib.calculate(9);

    printf("%d", out);
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

void Test::binarySearchTreeTest()
{
    BinarySearchTree tree;

    for (int i = 0; i < length; ++i)
    {
        tree.insert(tree.getRoot(), data[i]);
    }
    tree.traverse(tree.getRoot(), TraversalMode::INORDER);

    tree.traverse(tree.getRoot(), TraversalMode::PREORDER);

    tree.traverse(tree.getRoot(), TraversalMode::POSTORDER);
}


void Test::travellingSalesmanTest()
{

    City c1({0, 10, 15, 20});
    City c2({10, 0, 35, 25});
    City c3({15, 35, 0, 30});
    City c4({20, 25, 30, 0});

    std::vector<City> cities;

    cities.push_back(c1);
    cities.push_back(c2);
    cities.push_back(c3);
    cities.push_back(c4);

    int startingCity = 2;
    TravellingSalesman tsp(startingCity);

    tsp.calculateShortestPath(cities, startingCity);
}

void Test::hashTableTest()
{
    HashTable hashTable(10);

    hashTable.put("Mr. Mister");

    for (int i = 0; i < 1000; ++i)
    {
        std::string temp = std::to_string(i);
        hashTable.put(temp);
    }

    hashTable.print();

    hashTable.search("Mr. Mister");
}

void Test::quickSortTest()
{
    QuickSort quickSort;


    quickSort.sort(data, 0, length - 1);
}

void Test::print()
{
    for (int i = 0; i < length; ++i)
    {
        printf("Index %d Value %d\n", i, data[i]);
    }
}

void Test::epiTests()
{
    int test = 640;

    bitParity(test);
}

void Test::heapSortTests()
{
    BinaryHeap heap;

    print();
    heap.construct(data, length);
    heap.print();
}


void Test::bitWiseTests()
{

    int a = 0b00000100;
    int b = 0b00011000;
    int c = 0b00000000;

    int mask = a | b;

    c ^= (mask);

    std::string s = "";
    readModifyWrite(&a, &b, 3, 2);
    //s += int2bin(b);
    //printf("%s\n", s.c_str());

    int x = 4;
    int y = 10;

    //add
    int result = add(x, y);
    printf("%d + %d = %d\n",x, y, result);
    result = multiply(x, y);
    printf("%d * %d = %d\n",x, y, result);

    result = sub(x, y);
    printf("%d - %d = %d\n",x, y, result);

}


void Test::nintendoTests()
{
    /*
    static const int size = 4;
    int array[size] = { 1, 2, 127 , 254 };
    byteArrayToString(array, size);

    uint8_t hex_array[size] = { 0x13, 0x56, 0x9A, 0xBF };
    hexArrayToString(hex_array, size);

    std::cout << "Queue from two stacks" << std::endl;

    Queue q(10);
    q.enqueue(1);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(1000);

    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';

    std::cout << "Check Endianess" << std::endl;

    checkEndian();
    */

    /*
    SmartPointers sp;
    sp.moveExercise();
    sp.countExercise();
    */

    //FunctionPointerTests();


    int n = 10;
    float* testArrFloat;
    testArrFloat = (float*)(myMalloc(sizeof(float) * n));
    for (int i = 0; i < n; ++i)
    {
        testArrFloat[i] = i;
        printf("%d : %f\n", i, testArrFloat[i]);
    }

    float* testArrFloat2;
    testArrFloat2 = (float*)(myMalloc(sizeof(float) * n));
    for (int i = 0; i < n; ++i)
    {
        testArrFloat2[i] = i * 101.f;
        printf("%d : %f\n", i, testArrFloat2[i]);
    }

    myFree(testArrFloat);
    myFree(testArrFloat2);

    for (int i = 0; i < n; ++i)
    {
        testArrFloat[i] = i * 3.14;
        printf("%d : %f\n", i, testArrFloat[i]);
    }


    Base b;
    Derived d;

    Base_Ctor(&b);
    Derived_Ctor(&d);

    int x = Base_Add(&b, 2);
    int y = Base_Sub(&b, 2);
    printf("Base Add %d Base Sub %d\n", x, y);

    x = Derived_Add(&d, 2);
    y = Derived_Sub(&d, 2);
    printf("Derived Add %d Derived Sub %d\n", x, y);

}


void Test::fixedPointTests()
{
    FixedPoint fplib(16, false);
    fixedpoint_t  x = fplib.FloatToFixed(1.5);
    fixedpoint_t  y = fplib.FloatToFixed(5);
    fixedpoint_t  result = fplib.multiply(x, y);

    fplib.print(result);
}
