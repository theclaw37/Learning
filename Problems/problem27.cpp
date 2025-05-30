#include <vector>

namespace problem27
{
    int removeElement(std::vector<int>& nums, int val) 
    {
        int stackTop = nums.size() - 1;
        for (int idx = 0; idx <= stackTop; idx++)
        {
            if (nums[idx] == val)
            {
                std::swap(nums[idx--], nums[stackTop--]);
            }
        }

        return stackTop + 1;
    }
}