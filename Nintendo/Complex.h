//
// Created by Chris Howe on 8/29/20.
//
#pragma once

class Complex
{
public:
    Complex();
    Complex(float r, float i) : real(r), imag(i) {};

    float real { 0.f };
    float imag { 0.f };

    Complex add(Complex& a, Complex& b);
    Complex sub(Complex& a, Complex& b);
    Complex divide(Complex& a, Complex& b);
    Complex mult(Complex& a, Complex& b);
private:
};
