#include <vector>
#include <algorithm>

namespace problem16
{
    int threeSumClosest(std::vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());

        unsigned int referenceDif = std::numeric_limits<unsigned int>::max();
        int resultSum;

        for (size_t first = 0; first < nums.size() - 2; ++first)
        {
            if (first > 0 && nums[first] == nums[first-1]) continue;

            size_t second = first + 1;
            size_t third = nums.size() - 1;

            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third] - target;
                int absoluteSum = std::abs(sum);

                if (absoluteSum < referenceDif) 
                {
                    referenceDif = absoluteSum;
                    resultSum = sum + target;
                }

                if (sum == 0)
                {
                    return sum + target;
                }
                else if (sum < 0)
                {
                    ++second;
                    while (second < nums.size() && nums[second - 1] == nums[second]) ++second;
                }
                else //if (sum > 0)
                {
                    --third;
                    while (third > second && nums[third] == nums[third + 1]) --third;
                }
            }
        }

        return resultSum;
    }
}