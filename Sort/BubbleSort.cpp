//
// Created by Chris Howe on 7/31/20.
//

#include "../Utils.h"

// Worst case complexity O(n^2)
// Best case complexity O(n)
// Comparison Sort Class
// Space Complexity 1

void bubbleSort(int* data, int length)
{
    int i = 0;
    int j = 0;

    //Iterate through entire data set
    for (i = 0; i < length - 1; i++)
    {
        //for current index 'i' compare against all elements 'i' through 'j', if greater than swap values
        for (j = 0; j < (length - i - 1); j++)
        {
            if (data[j] > data[j+1])
            {
                swap(data[j], data[j+1]);
            }
        }
    }
}