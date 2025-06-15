#include <vector>
#include <algorithm>

namespace problem1200
{
    using namespace std;
    
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> results;
        int min = std::numeric_limits<int>::max();

        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] - arr[i - 1] < min)
            {
                results.resize(0);
                min = arr[i] - arr[i - 1];
                results.push_back({{arr[i - 1], arr[i]}});
            }
            else if (arr[i] - arr[i - 1] == min)
            {
                results.push_back({{arr[i - 1], arr[i]}});
            }
        }

        return results;
    }
}