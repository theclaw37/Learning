#include <string>
#include <stack>

namespace problem20
{
    bool isValid(std::string s) {
        std::stack<char> verify;
        
        for (const char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                verify.push(c);
            }
            else
            {
                if (verify.empty())
                    return false;
                if (c == ')')
                {
                    if (verify.top() != '(') return false;
                    verify.pop();
                }
                else if (c == ']')
                {
                    if (verify.top() != '[') return false;
                    verify.pop();
                }
                else if (c == '}')
                {
                    if (verify.top() != '{') return false;
                    verify.pop();
                }
            }
        }

        if (verify.size() == 0) 
            return true;
        return false;
    }
}