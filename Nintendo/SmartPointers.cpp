//
// Created by Chris Howe on 8/26/20.
//

#include "SmartPointers.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <utility>


using namespace std;

void SmartPointers::moveSwap(int &a, int &b)
{
    //using move allows you to swap the resources instead of copying them around
    int temp = move(a);
    a = move(b);
    b = move(temp);
}

void SmartPointers::moveExercise()
{
    //The move function really does very little work.
    // All move does is accept either an lvalue or rvalue argument,
    // and return it as an rvalue without triggering a copy construction

        string s = "Hello, World!";
        vector<string> v;
        //copies s
        v.push_back(s);
        cout << "S " << s << endl;
        cout << "V " << v[0] << " " << v[1] << endl;

        // uses the rvalue reference push_back(T&&) overload,
        // which means no strings will be copied; instead, the contents
        // of str will be moved into the vector.  This is less
        // expensive, but also means str might now be empty.

        //std::move() is a cast that produces an rvalue-reference to an object, to enable moving from it.
        v.push_back(move(s));
        cout << "S " << s << endl;
        cout << "V " << v[0] << " " << v[1] << endl;

        int a = 7;
        int b = 12;
        cout << "A " << a << " B " << b << endl;
        moveSwap(a, b);
        cout << "A " << a << " B " << b << endl;
        swap(a, b);
        cout << "A " << a << " B " << b << endl;
}


void SmartPointers::countExercise()
{
    int n = 8;


    for (int i = 0; i < n; ++i)
    {
        counters.push_back( make_unique<Counter>(i) );
    }

    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        k = 0;
        while (k++ < 4)
        {
            cout << "Counter : " << i << " = " << counters[i]->count() << endl;
        }
        cout << endl;
    }
}

