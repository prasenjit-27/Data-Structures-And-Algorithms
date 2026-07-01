class Solution {
public:
    int helper(vector<int>nums, int k) {

        int n = nums.size();

        int i = 0;
        int count = 0;
        unordered_map<int, int> x;

        for (int j = 0; j < n; j++) {

            x[nums[j]]++;

            while (x.size() > k) {

                x[nums[i]]--;
                if (x[nums[i]] == 0) {

                    x.erase(nums[i]);
                }
                i++;
            }

            count += j - i + 1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return helper(nums,k) - helper(nums,k-1);
    }
};