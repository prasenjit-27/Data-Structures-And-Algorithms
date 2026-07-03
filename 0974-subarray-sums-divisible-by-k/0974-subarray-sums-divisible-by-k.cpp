class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> mp;

        long long presum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i = 0; i<n; i++){

            presum += nums[i];

            int target = presum % k;

            if(target < 0) target+=k;

            count+= mp[target];

            mp[target]++;
        }

        return count;


        
    }
};