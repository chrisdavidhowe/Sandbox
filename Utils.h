//
// Created by Chris Howe on 7/31/20.
//

#pragma once

template <typename T>
void swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}
