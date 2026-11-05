#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
    static std::vector<int> evens;
    static std::vector<int> odds;

    static void init() {
        if (!evens.empty()) return;
        for (int len = 1; len <= 10; ++len) {
            int halfLen = (len + 1) / 2;
            int start = 1;
            for (int i = 1; i < halfLen; ++i) start *= 10;
            int end = start * 10;
            for (int i = start; i < end; ++i) {
                std::string s = std::to_string(i);
                std::string rev = s;
                std::reverse(rev.begin(), rev.end());
                std::string full = s + rev.substr(len % 2);
                long long val = std::stoll(full);
                if (val <= 2000000002LL) {
                    if (val % 2 == 0) evens.push_back(val);
                    else odds.push_back(val);
                }
            }
        }
    }

public:
    long long minOperations(std::vector<int>& nums) {
        init();
        long long totalOps = 0;
        for (int x : nums) {
            const auto& list = (x % 2 == 0) ? evens : odds;
            auto it = std::lower_bound(list.begin(), list.end(), x);
            int best = -1;
            int minDiff = 2e9;
            if (it != list.end()) {
                int diff = *it - x;
                if (diff < minDiff) {
                    minDiff = diff;
                    best = *it;
                }
            }
            if (it != list.begin()) {
                --it;
                int diff = x - *it;
                if (diff < minDiff) {
                    minDiff = diff;
                    best = *it;
                }
            }
            totalOps += (long long)minDiff / 2;
        }
        return totalOps;
    }
};

std::vector<int> Solution::evens;
std::vector<int> Solution::odds;