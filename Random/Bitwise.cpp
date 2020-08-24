//
// Created by Chris Howe on 8/6/20.
//

/* The value of a*b is same as (a*2)*(b/2) if b is even,
 * otherwise the value is same as ((a*2)*(b/2) + a).
 * In the while loop, we keep multiplying ‘a’ with 2 and keep dividing ‘b’ by 2.
 * If ‘b’ becomes odd in loop, we add ‘a’ to ‘res’.
 * When value of ‘b’ becomes 1, the value of ‘res’ + ‘a’, gives us the result.
 * */


#include <string>

unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int out = 0;

    // While second number doesn't become 1
    while (b > 0)
    {
        // If second number becomes odd, add the first number to result
        if (b & 1)
        {
            out += a;
        }

        // Double the first number
        a = a << 1;

        // Halve the second number
        b = b >> 1;
    }
    return out;
}

int multiply(int x, int y)
{
    int out = 0;
    while (y)
    {
        //if y is odd running sum x
        if (y & 1)
        {
            out += x;
        }
        x <<= 1;
        y >>= 1;
    }
    return out;
};

int add(int x, int y)
{
    unsigned int bit = 0;
    while (y)
    {
        //calculate carry bit
        bit = x & y;
        x ^= y;
        y = bit << 1;git
    }
    return x;
}

int sub(int x, int y)
{
    unsigned int bit = 0;
    while (y)
    {
        bit = ~x & y;
        x ^= y;
        y = bit << 1;
    }
    return x;
}

std::string int2bin(int a)
{
    std::string s;
    int k = 31;
    for (int i = 31; i >= 0; i--)
    {
        s[k--] = (a & 1) + '0';
        a >>= 1;
    }
    return s;
}
