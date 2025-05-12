#include <vector>
#include <string>

namespace problem22
{
    std::vector<std::string> generateParenthesis(int n) {
        const size_t solutionSize = n * 2;
        std::string solution;
        solution.resize(solutionSize, '.');

        std::vector<std::string> results;

        int index = 0;
        int open = 0;
        int closed = 0;

        while (index >= 0)
        {
            if (index >= solutionSize)
            {
                results.push_back(solution);
                --index;

                continue;
            }

            if (solution[index] == '.')
            {
                if (open < n)
                {
                    solution[index++] = '(';
                    ++open;
                    continue;
                }

                solution[index++] = ')';
                ++closed;
                continue;
            }

            if (solution[index] == '(')
            {
                if (closed < open - 1)
                {
                    solution[index++] = ')';
                    --open;
                    ++closed;
                    continue;
                }

                solution[index--] = '.';
                --open;
                continue;
            }

            if (solution[index] == ')')
            {
                solution[index--] = '.';
                closed--;
                continue;
            }
        }

        return results;
    }
}