#include <string>
#include <vector>
#include <print>
#include <array>

namespace problem17
{
    std::vector<std::string> letterCombinations(std::string digits) {
        const std::array<std::array<char, 4>, 10> ref = {{
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        }};

        for (int i = 0; i < ref.size(); ++i)
        {
            for (const auto& item : ref[i])
            {
                if (item)
                    std::print(" |{0}| ", item);
            }
        }

        return {};
    }
}