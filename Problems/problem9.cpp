#include <array>

namespace problem9
{
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;
        
        int reverse = 0;
        int original = x;
        while (x)
        {
            if (reverse <= std::numeric_limits<int>::max() / 10) reverse *= 10; 
            else return 0;

            reverse += x % 10;
            
            x /= 10;
        }

        return reverse == original;
    }
}