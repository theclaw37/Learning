#include <string>

using namespace std;

namespace problem28
{
    int strStr(string haystack, string needle) 
    {
        size_t matched = 0;
        // for (auto const & [index, character] : std::views::enumerate(haystack))
        for (size_t iter = 0; iter < haystack.length(); ++iter)
        {
            /* Possible improvement: 
                Do not reset the iterator all the way back to the start of the matching sequence.
                Instead, while the sequence is matching (i.e. matching > 0), keep a FIFO queue of 
                    places where haystack[iter] = needle[0], i.e. possible starting points in case 
                    we need to reset.
                This way, when we reset, we don't reset all the way back, but we reset, in order,
                    beginning from the first queue.pop() element, and each further reset,
                    we pop the next element from the queue.
            */
            if (haystack[iter] != needle[matched])
            {
                iter = iter - matched + 1;
                matched = 0;
            }

            if (haystack[iter] == needle[matched])
                matched++;

            if (matched == needle.length())
                return iter - matched + 1;
        }

        return -1;
    }
}