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

void FixedPoint::saturate(fixedpoint_t& x, int numBits)
{
    int max = (1 << numBits) - 1;
    int min = ~max + 1;
    if (x >= max) { x = max; }
    if (x <= min) { x = min; }
}

fixedpoint_t FixedPoint::FloatToFixed(float x)
{
    fixedpoint_t y = round(x * (1 << numFractionalBits_));
    return y;
}

float FixedPoint::FixedToFloat(fixedpoint_t x)
{
    float y = (float) x / (1 << numFractionalBits_);
    return y;
}

fixedpoint_t FixedPoint::multiply(fixedpoint_t x, fixedpoint_t y)
{
    //calculate product
    int64_t product = x * y;
    fixedpoint_t result = product >> numFractionalBits_;
    return result;
}

fixedpoint_t FixedPoint::sum(fixedpoint_t x, fixedpoint_t y)
{
    int64_t sum = (int64_t)x + y;
    return sum;
}

void FixedPoint::print(fixedpoint_t x)
{
    int t = x;
    std::string s = "000000000000000000.00000000000000";
    int k = 31;
    for (int i = 31; i >= 0; i--)
    {
        s[k--] = (x & 1) + '0';
        x >>= 1;
    }
    float f = FixedToFloat(t);
    cout << "Fixed Point " << t << endl;
    cout << "Binary " << s << endl;
    cout << "Float " <<  f << endl;
}

