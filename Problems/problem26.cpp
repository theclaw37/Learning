#include <vector>

namespace problem26
{
    int removeDuplicates(std::vector<int>& nums) {
        size_t where = 0;

        for (size_t fromWhere = 1; fromWhere < nums.size(); fromWhere++)
        {
            if (nums[where] != nums[fromWhere])
            {
                nums[++where] = nums[fromWhere];
            }
        }

        return where + 1;
    }
}