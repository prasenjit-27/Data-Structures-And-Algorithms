#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    int maxEqualAdjacentPairs(std::vector<int>& nums) {
        int alreadyEqual = 0;
        std::map<std::pair<int, int>, int> pairCounts;

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                alreadyEqual++;
            } else {
                int u = std::min(nums[i], nums[i + 1]);
                int v = std::max(nums[i], nums[i + 1]);
                pairCounts[{u, v}]++;
            }
        }

        int maxAdd = 0;
        for (const auto& entry : pairCounts) {
            maxAdd = std::max(maxAdd, entry.second);
        }

        return alreadyEqual + maxAdd;
    }
};