//
// Created by Chris Howe on 8/28/20.
//

//
// Implement below in C
//
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


//Forward declare
struct Base;
//

typedef struct {
    void (*Base)(struct Base*);
    void (*update)(struct Base*);
    int  (*access)(struct Base*);
} Base_Function_Table;

typedef struct {
    int a;
    Base_Function_Table *vtable;
} Base;

//create functions
void Base_Construct(Base* this) {this->vmt = &vtable; this->a = 10;}
void Base_Update(Base* this) {this->a++;}
int Base_Access(Base* this) {this->vtable->update(this); return this->a;}

//populate base function table
Base_Function_Table bft = {Base_Construct, Base_Update, Base_Access};

