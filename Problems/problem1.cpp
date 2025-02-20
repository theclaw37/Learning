#include <unordered_map>
#include <vector>

namespace problem1 
{
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::unordered_map<size_t, size_t> indices;
        for (size_t index = 0; index < nums.size(); ++index) 
        {
            if (indices.contains(target - nums[index]))
            {
                return 
                { 
                    static_cast<int>(index), 
                    static_cast<int>(indices[target - nums[index]]) 
                };
            }
            else
            {
                indices[nums[index]] = index;
            }
        }
        return {};
    }
}