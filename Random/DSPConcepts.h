//
// Created by Chris Howe on 8/6/20.
//

#ifndef SANDBOX_DSPCONCEPTS_H
#define SANDBOX_DSPCONCEPTS_H

a(0) = 0;
a(1) = 1;
a(n) = a(n-1) + a(n-2)


        int fib(int n)
        {
            if (n <= 1)
            {
                return n;
            }

            return fib(n - 1) + fib(n - 2);
        }

        int fibIter(int n)
        {
            if (n <= 1)
            {
                return n
            };

            int ret = 0;
            int temp1 = 0;
            int temp2 = 1;

            for (int i = 1; i < n; ++i)
            {
                ret = temp1 + temp2;
                temp2 = temp1;
                temp1 = ret;
            }
            return ret;
        }


#endif //SANDBOX_DSPCONCEPTS_H
