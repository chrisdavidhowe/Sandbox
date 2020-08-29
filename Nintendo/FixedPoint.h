//
// Created by Chris Howe on 8/28/20.
//

#pragma once

typedef int fixedpoint_t;

class FixedPoint
{
public:
    FixedPoint(int numFractionalBits, bool isSigned);
    float FixedToFloat(fixedpoint_t x);
    fixedpoint_t FloatToFixed(float x);
    void print(fixedpoint_t x);
    fixedpoint_t multiply(fixedpoint_t x, fixedpoint_t y);
    fixedpoint_t sum(fixedpoint_t x, fixedpoint_t y);
    fixedpoint_t subtract(fixedpoint_t x, fixedpoint_t y);
    fixedpoint_t divide(fixedpoint_t x, fixedpoint_t y);
    void saturate(fixedpoint_t& x, int numBits);
private:
    const int numFractionalBits_ { 0 };
    const int fractionalMask_ { 0 };
    const bool isSigned_ { false };
};
