//
// Created by Chris Howe on 7/31/20.
//

#include "../Utils.h"

int bubbleSort(int* data, int length)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < length; ++i)
    {
        for (j = 0; j < length; ++j)
        {
            if (data[i] < data[j])
            {
                swap(&data[i], &data[j]);
            }

            if (data[i] == data[j])
            {
            }
        }
    }
}