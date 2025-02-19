#include <vector>

namespace problem4 {

    size_t bSearchSplit(std::vector<int>& vec, size_t low, size_t high, int item)
    {
        size_t left = low, right = high;
        size_t mid;

        while (left <= right) 
        {
            mid = left + (right - left) / 2;

            if (mid == low || mid == high || (vec[mid - 1] <= item && vec[mid] >= item)) 
                return mid;

            if (vec[mid] < item) 
                left = mid;
            else 
                right = mid;
        }

        return mid;
    }


    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        size_t totalSize = nums1.size() + nums2.size();

        std::vector<int>& searchVector = nums1.size() <= nums2.size() ? nums1 : nums2;
        std::vector<int>& otherVector = nums1.size() <= nums2.size() ? nums2 : nums1;

        size_t halfSearch = searchVector.size() / 2;
        size_t halfOther = otherVector.size() / 2;

        size_t searchSplit = halfSearch;
        size_t otherSplit = halfOther;

        bool slor, srol;
        do
        {
            // search left other right
            slor = searchVector[searchSplit - 1] < otherVector[otherSplit];
            // search right other left
            srol = searchVector[searchSplit] > otherVector[otherSplit - 1];

            // these two are mutually exclusively false (they can't both be false at the same time)
            if (!slor) 
            {
                // search left of searchSplit
                searchSplit = bSearchSplit(searchVector, 0, searchSplit, otherVector[otherSplit]);
            }
            if (!srol)
            {
                // search right of searchSplit
                searchSplit = bSearchSplit(searchVector, searchSplit, searchVector.size(), otherVector[otherSplit - 1]);
            }
            // ensure the middle invariant
            otherSplit = halfOther - (searchSplit - halfSearch);        
        } 
        while (!(slor && srol));

        size_t itemsNeeded = totalSize % 2 ? 1 : 2;
        size_t itemsNeededLeft = itemsNeeded;
        float median = 0;
        while (itemsNeededLeft--) 
        {
            if (searchVector[searchSplit] <= otherVector[otherSplit]) 
            {
                median += searchVector[searchSplit++];
            } 
            else 
            {
                median += otherVector[otherSplit++];
            }
        }
        median /= itemsNeeded;
        

        return median;
    }
}