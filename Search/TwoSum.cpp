//
// Created by Chris Howe on 8/6/20.
//

#include <cstdio>

void twoSum(int* data, int length, int sum)
{
    int test = 0;
    bool found = false;
    for (int i = 0; i < length; ++i)
    {
        test = data[i];
        for (int j = i + 1; j < length; ++j)
        {
            if( test + data[j] == sum )
            {
                printf("[ %d, %d ]\n", test, data[j]);
                found = true;
            }
        }
    }
    if (!found)
    {
        printf("This sum is not possible in array!\n");
    }
}