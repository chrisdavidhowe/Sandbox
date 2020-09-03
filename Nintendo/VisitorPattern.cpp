
#include "VisitorPattern.h"

void Visitor::visit(Int *i)
{
    cout << "Int : " << i->value << endl;
}

void Visitor::visit(Float *f)
{
    cout << "Float : " << f->value << endl;
}

void Visitor::visit(Bool *b)
{
    cout << "Boolean : " << b->value << endl;
}