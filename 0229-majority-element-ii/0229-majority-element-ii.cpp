class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(auto i: nums) mp[i]++;

        int val = n/3;

        vector<int> ans;

        for(auto i: mp){

            if(i.second > val) ans.push_back(i.first);


        }

        return ans;
        
    }
};