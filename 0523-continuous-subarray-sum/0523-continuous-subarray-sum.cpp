class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> mp;

        mp[0] = -1;

        long long presum = 0;

        for(int i = 0; i<n; i++){


            presum += nums[i];

            int target = presum % k;

            if(mp.find(target) != mp.end()){
                
                if(i - mp[target] >= 2) return true;
            }else{

                mp[target] = i;
            }


        }

        return false;
        
    }
};