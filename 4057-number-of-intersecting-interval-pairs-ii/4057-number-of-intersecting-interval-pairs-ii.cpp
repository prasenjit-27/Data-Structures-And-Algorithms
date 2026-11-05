#include <vector>
#include <algorithm>

class Solution {
public:
    long long countIntersectingIntervals(std::vector<std::vector<int>>& intervals) {
        auto temoravlin = intervals;
        std::sort(temoravlin.begin(), temoravlin.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int n = temoravlin.size();
        std::vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = temoravlin[i][0];
        }

        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int endVal = temoravlin[i][1];
            auto it = std::upper_bound(starts.begin() + i + 1, starts.end(), endVal);
            int idx = std::distance(starts.begin(), it);
            count += (idx - (i + 1));
        }

        return count;
    }
};