//
// Created by Chris Howe on 8/29/20.
//

#include "Complex.h"


Complex Complex::add(Complex &a, Complex &b)
{
    Complex out;
    out.real = a.real + b.real;
    out.imag = a.imag + b.imag;
    return out;
}

Complex Complex::sub(Complex &a, Complex &b)
{
    Complex out;
    out.real = a.real - b.real;
    out.imag = a.imag - b.imag;
}

Complex Complex::mult(Complex& a, Complex& b)
{
    Complex out;
    out.real = (a.real * b.real) - (a.imag * b.imag);
    out.imag = (a.real * b.imag) + (a.imag * b.real);
    return out;
}

Complex Complex::divide(Complex& a, Complex& b)
{
    Complex out;
    float d = (b.real * b.real) + (b.imag * b.imag);

    out.real = (a.real * b.real) - (a.imag * b.imag);
    out.imag = (a.real * b.imag) + (a.imag * b.real);
    out.real /= d;
    out.imag /= d;
    return out;
}