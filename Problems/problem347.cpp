#include <vector>
#include <unordered_map>
#include <map>
#include <ranges>
#include <print>

namespace problem347
{
    using namespace std;
    
    vector<int> topKFrequent(vector<int>&& nums, int k) {
        std::unordered_map<int, size_t> keyToFreq;
        std::map<size_t, vector<int>> freqToKey;

        for (const auto & num : nums) ++keyToFreq[num];
        for (const auto & [number, freq] : keyToFreq) freqToKey[freq].push_back(number);

        std::vector<int> result;
        for (auto & items : freqToKey | views::reverse | views::values)
        {
            if (k == 0)
                break;

            for (int num : items | views::take(k)) {
                result.push_back(num);
            }

            k -= items.size();
        }

        return result;
    }
}