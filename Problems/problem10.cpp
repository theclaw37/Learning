#include <string>
#include <vector>

namespace problem10
{
    bool isMatch(std::string s, std::string p) 
    {
        size_t m = s.size() + 1;
        size_t n = p.size() + 1;
        std::vector<std::vector<bool>> table(m, std::vector<bool>(n, false));

        table[0][0] = true;

        // pattern matching on empty string
        for (size_t j = 1; j < n; ++j)
        {
            if (p[j-1] == '*')
                table[0][j] = table[0][j-2];
            else
                table[0][j] = false;
        }

        for (size_t i = 1; i < m; ++i)
        {
            for (size_t j = 1; j < n; ++j)
            {
                // characters match exactly, or there is a . that matches anything
                if (p[j-1] == '.' || p[j-1] == s[i-1])
                    // this matches only if  the strings without their respective two characters are also matching
                    table[i][j] = table[i-1][j-1];

                // pattern contains a star
                if (p[j-1] == '*')
                {
                    // this matches if it matched 0 times (imagine there is no star), regardless of the character before the star
                    table[i][j] = table[i][j-2];

                    // if the character before the star is actually matching the character in the string
                    if (p[j-2] == '.' || p[j-2] == s[i-1])
                        // this matches if the string without this matched character also matched
                        table[i][j] = table[i][j] || table[i-1][j];
                }

                // none of the above matched, so leave the table value on false
            }
        }

        // the value that represents the full pattern matching the full string
        return table[m-1][n-1];
    }
}