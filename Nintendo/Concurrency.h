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

using namespace std;

class Concurrency
{
public:
    void run();

    thread t1();
    thread t2();
    thread t3();
    thread t4();

    condition_variable cv;
    mutex mutex;
};