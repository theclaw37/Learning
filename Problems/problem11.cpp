#include <vector>

namespace problem11
{
    int maxArea(const std::vector<int>& height) {
        size_t left = 0;
        size_t right = height.size() - 1;

        int max = 0;

        while (left < right)
        {
            int min = std::min(height[left], height[right]);

            int value = (right - left) * min;

            if (value > max)
                max = value;
            
            int incLeft = height[left] <= height[right];
            int decRight = height[left] >= height[right];
            
            left += incLeft;
            right -= decRight;
        }

        return max;
    }
}