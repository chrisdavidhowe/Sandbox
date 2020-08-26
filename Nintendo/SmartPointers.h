//
// Created by Chris Howe on 8/26/20.
//

#pragma once

#include <memory>
#include <vector>

class Counter
{
public:
    Counter(int start) : count_(start) {};
    //Copy Constuctor
    Counter(const Counter& other) : count_(other.count_) {};
    // Move Constructor
    Counter(const Counter&& other) : count_(other.count_) {};
    int count() { return ++count_; };
private:
    int count_ {0};
};

class SmartPointers
{
public:
    void moveExercise();
    void moveSwap(int& a, int& b);
    void uniqueExercise();

    void countExercise();

    vector<unique_ptr<Counter>> counters;
};