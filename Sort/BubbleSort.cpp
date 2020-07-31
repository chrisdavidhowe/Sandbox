//
// Created by Chris Howe on 7/31/20.
//

#include "../Utils.h"

int bubbleSort(int* data, int length)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < (length - i); j++)
        {
            if (data[j] > data[j+1])
            {
                swap(&data[j], &data[j+1]);
            }

            if (data[j] == data[j+1])
            {
            }
        }
    }
}