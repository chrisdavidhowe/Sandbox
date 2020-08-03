//
// Created by Chris Howe on 7/31/20.
//

#pragma once

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

enum class SortDirection
{
    ASCENDING = 0,
    DESCENDING
};

