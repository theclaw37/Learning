#include <string_view>
#include <string>
#include <ranges>
#include <algorithm>

namespace problem6
{
    std::string convert(std::string s, int numRows) 
    {
        if (numRows == 1 || numRows >= s.length()) return s;

        numRows = numRows - 1;
        std::string res;
        res.reserve(s.length());

        for (int i = 0; i < s.length(); i += numRows * 2)
        {
            res.push_back(s[i]);
        }
        for (int i = 1; i < numRows; i++) 
        {
            int j = -numRows * 2;
            while (j < (int)s.length())
            {
                j += numRows * 2;
                if (j - i > 0 && j - i < s.length()) res.push_back(s[j - i]);
                if (j + i > 0 && j + i < s.length()) res.push_back(s[j + i]);
            }
        }
        for (int i = numRows; i < s.length(); i += numRows * 2)
        {
            res.push_back(s[i]);
        }

        return res;
    }
}