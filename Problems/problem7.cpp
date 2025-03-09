#include <limits>

namespace problem7
{
    int reverse(int x) {
        if (x == std::numeric_limits<int>::min()) return 0;
        int multiplier = 1;
        if (x < 0) multiplier = -1;

        x *= multiplier;
        int result = 0;

        while (x)
        {
            if (result <= std::numeric_limits<int>::max() / 10) result *= 10; 
            else return 0;

            result += x % 10;
            
            x /= 10;
        }

        result *= multiplier;

        return result;
    }
}