#include <string>
#include <algorithm>

namespace problem13
{
    int romanToInt(std::string s) {
        int value = 0;
        char prev = 0;
        std::ranges::for_each(s.begin(), s.end(), [&prev, &value](char c) {
            if (c == 'M') {
                if (prev == 'C') value += 800;
                else value += 1000;
            }
            else if (c == 'D') {
                if (prev == 'C') value += 300;
                else value += 500;
            }
            else if (c == 'C') {
                if (prev == 'X') value += 80;
                else value += 100;
            }
            else if (c == 'L') {
                if (prev == 'X') value += 30;
                else value += 50; 
            }
            else if (c == 'X') {
                if (prev == 'I') value += 8;
                else value += 10;
            }
            else if (c == 'V') {
                if (prev == 'I') value += 3;
                else value += 5;     
            }
            else if (c == 'I') {
                value += 1;
            }

            prev = c;
        });

        return value;
    }
}