//
// Created by Chris Howe on 8/10/20.
//


// Computer the number of bits set to 1 in an integer


//Brute Force
int bitParity(int x)
{
    int temp = x;
    int count = 0;
    int bit = 1;
    bool result = false;

    //sizeof is measured in bytes
    for (int i = 0; i < (sizeof(x) * 8); ++i)
    {
        // test if bit is 0 or 1 based on a bitwise & operator that gets shifted
        // bitwise & returns true if 1, 0 else
        result = temp & bit;

        if (result)
        {
            count++;
        }

        printf("Bit %d : %d\n", i, result);

        bit = bit << 1;
    }

    printf("Number of 1 bits : %d\n", count);
}

