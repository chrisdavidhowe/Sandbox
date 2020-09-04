
    #include <string>

    using namespace std;

    int myAtoi(string str)
    {
        int len = str.size();
        int sign = 1;

        long ans = 0; //important to take long to avoid any runtime error faced with int

        for (int i = 0; i < len; i++)
        {
            char x = str[i];
            if (x == '-')
            {
                sign = -1;
            }
            else if ( (x >= '0') && (x <= '9'))
            {
                ans = ans * 10 + (x - '0');
            }
        }
        return ans * sign;
    }

    string myIntToString(int input)
    {
        int x = abs(input);
        string output;
        string sign;

        (input < 0) ? sign = "-" : sign = "";

        while (x)
        {
            output += (x % 10) + '0';
            x /= 10;
        }

        output += sign;
        reverse(output.begin(), output.end());

        return output;
    }
