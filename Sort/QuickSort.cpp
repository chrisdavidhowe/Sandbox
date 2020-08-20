//
// Created by Chris Howe on 8/7/20.
//

#include "QuickSort.h"
#include "../Utils.h"

void QuickSort::sort(int *data, int low, int high)
{
    if (low < high)
    {
        int part_i = partition(data, low, high);
        sort(data, low, part_i - 1);
        sort(data, part_i + 1, high);
    }
}

int QuickSort::partition(int* data, int low, int high)
{

    int pivot = data[high];

    int low_p = low;

    for (int i = low; i < high; ++i)
    {
        if (data[i] < pivot)
        {
            swap(data[i], data[low_p]);
            low_p++;
        }
    }

    swap(data[low_p], data[high]);
    return low_p;
}
