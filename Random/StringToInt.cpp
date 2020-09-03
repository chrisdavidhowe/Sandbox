
    #include <string>

    using namespace std;

    int myAtoi(string str)
    {

        int len = str.size();
        int sign = 1;

        long ans = 0; //important to take long to avoid any runtime error faced with int

        for (int i = 0; i < len; i++)
        {
            int x = str[i]; // converting the string to integer

            if (x == '-')
            {
                sign = -1;
            }
            else if(x == '+')
            {
                sign = 1;
            }
            else if (x >= '0' && x <= '9')
            {
                ans = ans * 10 + (x - '0'); //else will multiply ans by 10 and add the our digit in the end
                if (ans > INT32_MAX) { return INT32_MAX; }
                if (ans < INT32_MIN) { return INT32_MIN; }
            }
        }
        return ans * sign;
    }
