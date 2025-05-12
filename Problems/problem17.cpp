#include <string>
#include <vector>
#include <array>

namespace problem17
{
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty())
            return {};

        const std::array<std::array<char, 2>, 10> phoneRef = {{
            {},
            {},
            {'a', 'c'},
            {'d', 'f'},
            {'g', 'i'},
            {'j', 'l'},
            {'m', 'o'},
            {'p', 's'},
            {'t', 'v'},
            {'w', 'z'},
        }};

        // aprox 3...4 ^ number_of_digits
        std::vector<std::string> result;
        result.reserve(std::pow(3, digits.size()));

        // exactly number_of_digits for each solution
        std::string backString(digits.size(), '\0');
        size_t backTop = digits.size();

        for (size_t i = 0; i < digits.size(); ++i)
        {
            backString[i] = phoneRef[digits[i] - 48][0];
        }

        while(true)
        {
            if (backTop > digits.size())
            {
                return result;
            }
            else if (backTop == digits.size())
            {
                result.push_back(backString);
                --backTop;
            }
            else
            {
                ++backString[backTop];
                if (backString[backTop] == phoneRef[digits[backTop] - 48][1] + 1)
                {
                    --backTop;
                } 
                else
                {
                    if (backString[backTop] > phoneRef[digits[backTop] - 48][1] + 1)
                        backString[backTop] = phoneRef[digits[backTop] - 48][0];
                    ++backTop;
                }
            }
            
        }

        return result;
    }
}