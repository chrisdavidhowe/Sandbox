//
// Created by Chris Howe on 8/26/20.
//


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

void FunctionPointerTests()
{
    int (*fp)(int,int);
    fp = &addFunc;
    fp(4,5);
    fp = &multFunc;
    fp(4,5);

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

}