//
// Created by Chris Howe on 8/28/20.
//

#include "OOP.h"


//
// Implement below in C
//
/*
class Base
{
public:
    int a;
    int b;
    virtual int add(int n) { return n+1; }
};

class Derived: public Base
{
public:
    int c;
    virtual int add(int n) override { return n+2; }
};
*/

struct Base;

struct Base_Functable
{
    void (*Base)(struct Base*);
    int  (*add)(struct Base*, int);
    int  (*sub)(struct Base*, int);
};

struct Base {
    Base_Functable *vtable;
    int a;
    int b;
};

void Base_Ctor(Base*);
int Base_Add(Base* b, int a);
int Base_Sub(Base* b, int a);

Base_Functable B_functable = { Base_Ctor, Base_Add, Base_Sub };

void Base_Ctor(Base* b)
{
    printf("Constructing Base Class\n");
    b->vtable = &B_functable;
}
int Base_Add(Base* b, int n) {return n + 1; }
int Base_Sub(Base* b, int n) {return n - 1; }

struct Derived;

struct Derived_Functable
{
    void (*Derived)(struct Derived*);
    int  (*add)(struct Derived*, int);
    int  (*sub)(struct Derived*, int);
};

struct Derived
{
    Base base;
    Derived_Functable vtable;
    int c;
};

void Derived_Ctor(Derived* d);
int Derived_Add(struct Derived*, int n);
int Derived_Sub(struct Derived*, int n);

Derived_Functable D_functable = {Derived_Ctor, Derived_Add, Derived_Sub};

void Derived_Ctor(struct Derived* d)
{
    printf("Constructing Derived Class\n");
    d->base.vtable = (Base_Functable*)&D_functable;
    Base_Ctor(&d->base);
}

int Derived_Add(struct Derived* d, int n)
{
    return n + 2;
}

int Derived_Sub(struct Derived* d, int n)
{
    return d->base.vtable->sub(&d->base, n);
}