//
// Created by Chris Howe on 8/26/20.
//

#include <functional>

int addFunc(int a, int b)
{
    int out = a + b;
    printf("%d + %d = %d\n", a, b, out);
    return out;
}

int multFunc(int a, int b)
{
    int out = a * b;
    printf("%d * %d = %d\n", a, b, out);
    return out;
}

int subFunc(int a, int b)
{
    int out = a - b;
    printf("%d - %d = %d\n", a, b, out);
    return out;
}

void doSomeMath( int (*fp)(int,int), int a, int b )
{
    printf("Doing some math!\n");
    fp(a, b);
}

void FunctionPointerTests()
{
    //C style
    //int (*fp) (int,int);
    //C++ style
    std::function<int(int, int)> fp;

    fp = &addFunc;
    fp(4,5);
    fp = &multFunc;
    fp(4,5);

    char addr[100];
    sprintf(addr, "%p", subFunc);
    unsigned long long mem_addr = strtoll(addr, NULL, 0);
    printf("Memory address of subtraction function %d\n", mem_addr);
    fp = (int (*) (int,int))(mem_addr);
    fp(4,3);

    printf("\nArray of Function Pointers\n");
    int (*fparr[2])(int,int);
    fparr[0] = &addFunc;
    fparr[1] = &multFunc;

    for (int i = 0; i < 8; ++i)
    {
        if (i & 1)
        {
            fparr[0](i, i+1);
        }
        else
        {
            fparr[1](i, i+1);
        }
    }

    doSomeMath(&addFunc, 4, 8);
    doSomeMath(&multFunc, 4, 8);
    doSomeMath(&subFunc, 4, 8);
}