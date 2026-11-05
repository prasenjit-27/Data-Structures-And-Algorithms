#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> maxSingleNumber(const std::vector<int>& nums, int k) {
        std::vector<int> res;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!res.empty() && res.back() < num && drop > 0) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    bool greater(const std::vector<int>& nums1, int i, const std::vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        if (j == nums2.size()) return true;
        if (i < nums1.size() && nums1[i] > nums2[j]) return true;
        return false;
    }

    std::vector<int> merge(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> res(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (greater(nums1, i, nums2, j)) {
                res[k++] = nums1[i++];
            } else {
                res[k++] = nums2[j++];
            }
        }
        while (i < nums1.size()) res[k++] = nums1[i++];
        while (j < nums2.size()) res[k++] = nums2[j++];
        return res;
    }

public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        std::vector<int> best;
        int start = std::max(0, k - n);
        int end = std::min(k, m);
        for (int i = start; i <= end; ++i) {
            std::vector<int> candidate1 = maxSingleNumber(nums1, i);
            std::vector<int> candidate2 = maxSingleNumber(nums2, k - i);
            std::vector<int> merged = merge(candidate1, candidate2);
            if (merged > best) {
                best = merged;
            }
        }
        return best;
    }
};