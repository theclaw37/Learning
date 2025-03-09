#include <string>

namespace problem5
{
    // std::string longestPalindrome(std::string s)
    // {
    //     size_t length = 0;
    //     size_t stringLength = s.size();

    //     size_t maxLength = 0;
    //     size_t from = 0;
    //     size_t start = 0;

    //     while (start < stringLength)
    //     {
    //         size_t end = start;
    //         while (end < stringLength - 1 && s[end] == s[end + 1])
    //         {
    //             ++end;
    //         }
    //         while (end < stringLength - 1 && start > 0 && s[end + 1] == s[start - 1])
    //         {
    //             ++end;
    //             --start;
    //         }
    //         length = end - start + 1;
    //         if (length > maxLength)
    //         {
    //             maxLength = length;
    //             from = start;
    //         }
    //         if (start != end)
    //         {
    //             start = end;
    //         }
    //         else
    //         {
    //             start++;
    //         }
    //     }
    //     return s.substr(from, maxLength);
    // }

    std::string longestPalindrome(std::string s)
    {
        size_t stringLength = s.size();

        size_t maxPalindromeLength = 1;
        size_t maxPalindromeBegin = 0;

        for (size_t i = 0; i < stringLength; ++i)
        {
            size_t end = i;
            size_t start = i;
            while (end < stringLength - 1 && s[end] == s[end + 1])
            {
                ++end;
            }
            while (end < stringLength - 1 && start > 0 && s[end + 1] == s[start - 1])
            {
                ++end;
                --start;
            }
            size_t currentLength = end - start + 1;

            if (currentLength > maxPalindromeLength)
            {
                maxPalindromeLength = currentLength;
                maxPalindromeBegin = start;
            }
        }

        return s.substr(maxPalindromeBegin, maxPalindromeLength);
    }
}