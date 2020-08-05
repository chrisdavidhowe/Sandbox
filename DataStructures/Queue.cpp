//
// Created by Chris Howe on 8/5/20.
//

#include "Queue.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Queue::Queue(int cap):
    capacity_(cap)
{
    data_ = new int[capacity_];
    memset(data_, 0, sizeof(int) * capacity_);
    length_ = 0;
}

Queue::~Queue()
{
    delete [] data_;
}

void Queue::enqueue(int value)
{
    if (length_ < capacity_)
    {
        data_[length_] = value;
        length_++;
    }
    else
    {
        printf("Reached queue capacity!\n");
    }
}

void Queue::dequeue()
{
    data_[length_] = 0;
    length_--;
}

int Queue::getFront()
{
    return data_[0];
}

int Queue::getRear()
{
    return data_[length_ - 1];
}

void Queue::print()
{
    printf("\nQueue Length %d \n", length_);
    printf("Queue Head %d \n", data_[0]);
    for (int i = 1; i < length_ - 1; ++i)
    {
        printf("Queue Data %d \n", data_[i]);
    }
    printf("Queue Rear %d \n", data_[length_ - 1]);
}