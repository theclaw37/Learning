#include <vector>

namespace problem605
{
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++)
            {
                int left = i == 0 ? 0 : flowerbed[i-1];
                int right = i == flowerbed.size() - 1 ? 0 : flowerbed[i+1];

                if (!left && !right && !flowerbed[i])
                {
                    --n;
                    ++i;
                }
            }
        return n <= 0;
    }
}