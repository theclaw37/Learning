#include <vector>
#include <iostream>

#include "problem4.h"

using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 5, 8, 12, 15};
    vector<int> nums2 = {0, 6, 7, 9, 20};
    std::print("Median: {0}\n", problem4::findMedianSortedArrays(nums1, nums2));
    return 0;
}