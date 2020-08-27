//
// Created by Chris Howe on 8/26/20.
//

#pragma once

#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "semaphore.h"

#include "SmartPointers.h"

using std;

class Concurrency
{
public:
    void run();

    void thread1();
    void thread2();
    void thread3();

};