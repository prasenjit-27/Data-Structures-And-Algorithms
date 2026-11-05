#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    long long shadowPairs(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> nextSmaller(n, n);
        std::stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        std::vector<std::pair<int, int>> indexedNums(n);
        for (int i = 0; i < n; ++i) {
            indexedNums[i] = {nums[i], i};
        }
        std::sort(indexedNums.begin(), indexedNums.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        auto bitAdd = [&](std::vector<int>& bit, int idx, int val) {
            for (++idx; idx < (int)bit.size(); idx += idx & -idx) bit[idx] += val;
        };

        auto bitQuery = [&](const std::vector<int>& bit, int idx) {
            int sum = 0;
            for (++idx; idx > 0; idx -= idx & -idx) sum += bit[idx];
            return sum;
        };

        std::vector<int> bit(n + 1, 0);
        long long totalShadowPairs = 0;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && indexedNums[j].first == indexedNums[i].first) {
                j++;
            }

            for (int k = i; k < j; ++k) {
                int idx = indexedNums[k].second;
                int r = nextSmaller[idx];
                if (idx + 1 < r) {
                    totalShadowPairs += bitQuery(bit, r - 1) - bitQuery(bit, idx);
                }
            }

            for (int k = i; k < j; ++k) {
                int idx = indexedNums[k].second;
                bitAdd(bit, idx, 1);
            }

            i = j;
        }

        return totalShadowPairs;
    }
};