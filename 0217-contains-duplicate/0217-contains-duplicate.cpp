class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {


        unordered_set<int> x;

        for(auto i: nums){

            if(x.count(i)){

                return true;


            }

            x.insert(i);
        }

        


        return false;


        
    }
};