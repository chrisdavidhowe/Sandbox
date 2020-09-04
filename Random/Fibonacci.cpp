//
// Created by Chris Howe on 8/5/20.
//

#include "Fibonacci.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

int Fibonacci::calculate(int n)
{
    int output = 0;
    if (n <= 1){ return n; }

    //Recursive
    if ( !memo.count(n) ) {
        output = (calculate(n - 1) + calculate(n - 2));
        memo.insert({n, output});
    }
    else
    {
        output = memo.at(n);
    }


    //Iterative
    /*
    int n1 = 0;
    int n2 = 1;
    for (int i = 0; i < n; ++i)
    {
        output = n1 + n2;
        n2 = n1;
        n1 = output;
        //cout << output << ", ";
    }
    */

    cout << output << ", ";
    return output;
}