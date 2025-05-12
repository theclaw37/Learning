#include <vector>
#include <algorithm>

namespace problem18
{
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;   

        if (nums.size() < 4) return result;

        for (size_t first = 0; first < nums.size() - 3; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            for (size_t second = first + 1; second < nums.size() - 2; ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                size_t third = second + 1;
                size_t fourth = nums.size() - 1;

                while (third < fourth)
                {
                    long long dif = (long long)target - nums[first] - nums[second] - nums[third] - nums[fourth];

                    if (dif == 0)
                    {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                    }
                    if (dif >= 0)
                    {
                        ++third;
                        while (third < nums.size() && nums[third - 1] == nums[third])
                            ++third;
                    }
                    if (dif <= 0)
                    {
                        --fourth;
                        while (fourth > third && nums[fourth] == nums[fourth + 1])
                            --fourth;
                    }
                }
            }
        }

        return result;
    }
}