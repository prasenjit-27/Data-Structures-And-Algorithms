class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefix = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            prefix += nums[i];
            int target = prefix - k;
            if (mp.find(target) != mp.end()) {

                ans += mp[target];
            }

            mp[prefix]++;
        }

        return ans;
    }
};