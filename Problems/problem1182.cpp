#include <vector>
#include <iostream>

namespace problem1182
{
    std::vector<int> shortestDistanceColor(std::vector<int> const &colors, [[maybe_unused]] std::vector<std::vector<int>> const &queries)
    {
        std::array<std::vector<int>, 4> discreteColors{{{}, {}, {}, {}}};
        std::array<std::vector<int>, 4> contiguousColors;
        std::array<int, 4> contiguousToDiscreteIndices{0, -1, -1, -1};

        std::vector<int> result;

        for (size_t i = 0; i < colors.size(); ++i)
        {
            contiguousToDiscreteIndices[colors[i]]++;
            discreteColors[colors[i]].push_back(i);
            contiguousColors[1].push_back(contiguousToDiscreteIndices[1]);
            contiguousColors[2].push_back(contiguousToDiscreteIndices[2]);
            contiguousColors[3].push_back(contiguousToDiscreteIndices[3]);
        }
        discreteColors[1].push_back(discreteColors[1].back());
        discreteColors[2].push_back(discreteColors[2].back());
        discreteColors[3].push_back(discreteColors[3].back());

        for (size_t i = 0; i < queries.size(); ++i)
        {
            const auto &index = queries[i][0];
            const auto &color = queries[i][1];
            const auto &leftItemIndex = contiguousColors[color][index];

            if (leftItemIndex == -1)
                result.push_back(-1);
            else
            {
                int betweenLeft = discreteColors[color][leftItemIndex];
                int betweenRight = discreteColors[color][leftItemIndex + 1];

                int distLeft = std::abs((int)index - betweenLeft);
                int distRight = std::abs((int)index - betweenRight);
                int minDist = std::min(distLeft, distRight);

                result.push_back(minDist);
            }
        }

        return result;
    }
}