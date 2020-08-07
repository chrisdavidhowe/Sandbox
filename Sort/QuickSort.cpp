//
// Created by Chris Howe on 8/7/20.
//

#include "QuickSort.h"
#include "../Utils.h"

void QuickSort::sort(int *data, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(data, low, high);
        //Before partition index
        sort(data, low, partition_index - 1);
        //After the partition index
        sort(data, partition_index + 1, high);
    }
}

int QuickSort::partition(int* data, int low, int high)
{
    //Assign pivot value
    pivot = data[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (data[j] < pivot)
        {
            // increment index of smaller element
            i++;
            //swap values
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[high]);

    //return the partition index
    // where the pivot belongs
    return (i + 1);
}
