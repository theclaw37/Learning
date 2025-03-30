#include <string>

namespace problem8
{
    int myAtoi(std::string s) 
    {
        size_t idx = 0;

        while (s[idx] == ' ') idx++;

        int sign = 1;
        if (s[idx] == '-')
        {
            sign = -1;
            idx++;
        }
        else if (s[idx] == '+')
        {
            idx++;
        }
        else if (s[idx] < '0' || s[idx] > '9') return 0;

        int result = 0;

        while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9')
        {
            int digit = s[idx] - '0';
            if (sign == 1)
            {
                if (result <= std::numeric_limits<int>::max() / 10)
                {
                    result *= 10; 
                }
                else
                    return std::numeric_limits<int>::max();

                if (result <= std::numeric_limits<int>::max() - digit)
                {
                    result += s[idx] - '0';
                }
                else
                    return std::numeric_limits<int>::max();
            }
            if (sign == -1)
            {
                if (result <= std::numeric_limits<int>::max() / 10)
                {
                    result *= 10; 
                }
                else
                    return std::numeric_limits<int>::min();

                if (result - 1 < std::numeric_limits<int>::max() - digit)
                {
                    result += s[idx] - '0';
                }
                else
                    return std::numeric_limits<int>::min();
            }
            idx++;
        }

        return sign * result;
    }
}