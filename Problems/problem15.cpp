#include <vector>
#include <algorithm>
#include <print>

namespace problem15
{
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        
        const size_t nums_size = nums.size();

        for (size_t first = 0; first < nums.size() - 2; ++first)
        {
            if (first > 0 && nums[first] == nums[first-1]) continue;
            if (nums[first] > 0) continue;

            size_t second = first + 1;
            size_t third = nums.size() - 1;

            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];

                if (sum == 0)
                {
                    result.push_back({ nums[first], nums[second], nums[third] });
                }
                if (sum <= 0)
                {
                    ++second;
                    while (second < nums.size() && nums[second - 1] == nums[second]) ++second;
                }
                if (sum >= 0)
                {
                    --third;
                    while (third > second && nums[third] == nums[third + 1]) --third;
                }
            }
        }

        return result;
    }
}