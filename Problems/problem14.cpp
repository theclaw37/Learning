#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

namespace problem14 
{
    std::string longestCommonPrefix(const std::vector<std::string>& strs) 
    {
        if (strs.empty()) return "";

        size_t current = 0;
        while (strs[0].length() > current)
        {
            char currentChar = strs[0][current];
            
            for (const std::string& item : (strs | std::views::drop(1)))
            {
                if (!(item.size() > current && item[current] == currentChar))
                    return strs[0].substr(0, current);
            }

            current++;
        }
    }
};