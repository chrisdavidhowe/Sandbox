//
// Created by Chris Howe on 8/6/20.
//

#include "BinaryHeap.h"
#include "../Utils.h"

// Function to heapify the tree
void BinaryHeap::heapify(std::vector<int> &heap, int index)
{
    int size = heap.size();

    // Find the largest among root, left child and right child
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    // Swap and continue heapifying if root is not largest
    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        heapify(heap, largest);
    }
}


void BinaryHeap::construct(int *data, int length)
{
    data_ = data;

    for (int i = 0; i < length; ++i)
    {
        heapTree_.push_back(data[i]);
    }

    heapify(heapTree_, 0);
}

void BinaryHeap::print()
{
    for (int i = 0; i < heapTree_.size(); ++i)
    {
        printf("%d\n", heapTree_.at(i));
    }
}