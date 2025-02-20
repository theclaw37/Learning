#include <vector>
#include <print>

namespace problem4 
{
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int totalSize = nums1Size + nums2Size;
        
        if (nums1Size > nums2Size)
        {
            std::swap(nums1, nums2);
            std::swap(nums1Size, nums2Size);
        }
    
        int left = 0, right = nums1Size;
        while (left <= right) 
        {
            int midNums1 = (left + right) / 2;
            int midNums2 = (nums1Size + nums2Size + 1) / 2 - midNums1;

            int nums1LeftMax = midNums1 == 0 ? std::numeric_limits<int>::min() : nums1[midNums1 - 1];
            int nums2RightMin = midNums2 == nums2Size ? std::numeric_limits<int>::max() : nums2[midNums2];
            int nums1RightMin = midNums1 == nums1Size ? std::numeric_limits<int>::max() : nums1[midNums1];            
            int nums2LeftMax = midNums2 == 0 ? std::numeric_limits<int>::min() : nums2[midNums2 - 1];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) 
            {
                // All good, we found the split
                if (totalSize % 2 == 0)
                    // we got an even number of elements, so there's two medians
                    return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
                else
                    // we got an odd number of elements, so there's only one median
                    return std::max(nums1LeftMax, nums2LeftMax);
            }

            if (nums1LeftMax > nums2RightMin)
                // Too far right, go left
                right = midNums1 - 1;
            else
                // Too far left, go right
                left = midNums1 + 1;
        }
        return 0;
    }
}