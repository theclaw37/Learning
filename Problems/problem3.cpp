#include <string>
#include <array>

namespace problem3
{
    int lengthOfLongestSubstring(std::string s) {
        std::array<size_t, 128> charLastSeenIndex{};

        size_t longestSubstring = 0;
        
        size_t left = 0;
        for (size_t right = 0; right < s.length(); ++right) {
            if (charLastSeenIndex[s[right]] != 0) {
                left = std::max(charLastSeenIndex[s[right]], left);
            }

            longestSubstring = std::max(right - left + 1, longestSubstring); 
            
            charLastSeenIndex[s[right]] = right + 1;
        }

        return longestSubstring;
    }
}