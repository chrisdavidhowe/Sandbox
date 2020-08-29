//
// Created by Chris Howe on 8/28/20.
//

#include "FixedPoint.h"
#include <cstdint>
#include <iostream>
#include <math.h>

using namespace std;

FixedPoint::FixedPoint(int numFractionalBits, bool isSigned) :
    numFractionalBits_(numFractionalBits),
    fractionalMask_( (1 << numFractionalBits_) - 1 ),
    isSigned_(isSigned)
{
}

fixedpoint_t FixedPoint::FloatToFixed(float x)
{

    fixedpoint_t y = (x * (1 << numFractionalBits_)) / numFractionalBits_;

    //multiply by 2^N where N is the fractional bit
    if (isSigned_)
    {
        //get twos complement if signed and negative, bit inversion and pull LSB high
        if (x < 0) {
            y = ~y + 1;
        }
    }
    return y;
}

float FixedPoint::FixedToFloat(fixedpoint_t x)
{
    //take absolute value of x
    int sign = 1;
    if (isSigned_)
    {
        if (x < 0)
        {
            x = ~x - 1;
            sign = -1;
        }
    }

    float y = (float) ( x * numFractionalBits_ ) / (1 << numFractionalBits_);
    return y * sign;
}

void FixedPoint::print(fixedpoint_t x)
{
    int t = x;
    std::string s = "000000000000000000.00000000000000";
    int k = 31;
    for (int i = 31; i >= 0; i--)
    {
        s[k--] = (x & 1) + '0';
        if (i == numFractionalBits_ - 1)
        {
            s[k--] = '.';
        }
        x >>= 1;
    }
    float f = FixedToFloat(t);
    cout << "Fixed Point " << t << endl;
    cout << "Binary " << s << endl;
    cout << "Float " <<  f << endl;
}