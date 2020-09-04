//
// Created by Chris Howe on 8/5/20.
//

#pragma once

#include <map>

class Fibonacci
{
public:
    int calculate(int n);
private:
    std::map<int, int> memo;
};