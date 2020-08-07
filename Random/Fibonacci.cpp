//
// Created by Chris Howe on 8/5/20.
//

#include "Fibonacci.h"

int Fibonacci::calculate(int n)
{
    int output = 0;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        auto iterator = memoization_map_.find(n);
        if ( iterator != memoization_map_.end() )
        {
            output = iterator->second;
            return output;
        }
        else
        {
            memoization_map_.insert(std::pair<int, int>(n, output));
        }

        output = (calculate(n - 1) + calculate(n - 2));
        return output;
    }
}