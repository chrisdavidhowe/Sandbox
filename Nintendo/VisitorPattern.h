//
// Created by Chris Howe on 8/26/20.
//
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace std;
class Float;
class Int;
class Bool;

class Visitor
{
public:
    void visit(Float* f);
    void visit(Int* i);
    void visit(Bool* b);
};

class Types
{
public:
    virtual void accept(Visitor* visitor);
};

class Float : public Types
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }
    float value { 3.14f };
};

class Int : public Types
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }
    int value { 100 };
};

class Bool : public Types
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }
    bool value { false };
};