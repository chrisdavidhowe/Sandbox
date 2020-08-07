//
// Created by Chris Howe on 8/7/20.
//

#pragma once

class QuickSort
{
public:
    void sort(int* data, int low, int high);
    int partition(int* data, int low, int high);
private:
    int pivot;
};
