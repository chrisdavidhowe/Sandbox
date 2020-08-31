//
// Created by Chris Howe on 8/28/20.
//

#pragma once

#include <iostream>
using namespace std;

class Food
{
public:
    virtual ~Food() { cout << "Throwing out Food" << endl; };
    virtual void Print() { cout << "Food" << endl; };
};

class Pizza : public Food
{
public:
    ~Pizza() { cout << "Throwing out Pizza" << endl; };
    void Print() override { cout << "Pizza" << endl; };
};
