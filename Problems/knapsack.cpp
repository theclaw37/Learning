#include <vector>

namespace knapsack
{
    template <size_t S>
    int knapsack(int knapsackCapacity, const std::array<int, S>& weights, const std::array<int, S>& values)
    {
        std::vector<int> maxGains(knapsackCapacity + 1);

        for (size_t items = 0; items < S; ++items)
        {
            for (size_t knapsackMaxWeight = knapsackCapacity; static_cast<int>(knapsackMaxWeight) >= 0; --knapsackMaxWeight)
            {
                const bool canUseItem = ((int)knapsackMaxWeight - weights[items] >= 0);
                maxGains[knapsackMaxWeight] = std::max(
                    maxGains[knapsackMaxWeight], 
                    canUseItem ? (maxGains[knapsackMaxWeight - static_cast<size_t>(weights[items])] + values[items]) : 0);
            }
        }


        return maxGains[knapsackCapacity];
    }

    int knapsack
}