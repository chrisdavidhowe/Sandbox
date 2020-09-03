//
// Created by Chris Howe on 9/3/20.
//

#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Packaging
{
public:
    virtual void pack();
};

class Wrapper : public Packaging
{
    void pack() override
    {
        cout << " Wrapping a ";
    }
};

class Bottle : public Packaging
{
    void pack() override
    {
        cout << " Bottling a ";
    }
};

class Item
{
protected:
    virtual void describe();
    virtual Packaging* package();
    virtual void cost();
};

class Burger : public Item
{
public:
    Packaging* package() override
    {
        return new Wrapper();
    }
};

class Drink : public Item
{
public:
    Packaging* package() override
    {
        return new Bottle();
    }
};

class VeggieBurger : public Burger
{
    void describe() override
    {
        Packaging* p = package();
        p->pack();
        cout << " Veggie Burger " <<
    }

    void cost() override
    {
        cout << " $2.50 ";
    }
};

class CheeseBurger : public Burger
{
    void describe() override
    {
        Packaging* p = package();
        p->pack();
        cout << " Cheese Burger ";
    }

    void cost() override
    {
        cout << " $3.25 ";
    }
};

class Soda : public Drink
{
    void describe() override
    {
        Packaging* p = package();
        p->pack();
        cout << " Cold Soda ";
    }

    void cost() override
    {
        cout << " $1.25 ";
    }
};

class Beer : public Drink
{
    void describe() override
    {
        Packaging* p = package();
        p->pack();
        cout << " Warm Beer ";
    }

    void cost() override
    {
        cout << " $5.00 ";
    }
};