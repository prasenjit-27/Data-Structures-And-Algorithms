class Solution {
public:

    int bin(vector<int>& nums, int target, int st, int end){

        if(end < st) return -1;

        int mid = st + (end - st)/2;

        if(target == nums[mid])return mid;
        else if(target < nums[mid]) return bin(nums, target, st, mid-1);
        else return bin(nums, target, mid+1, end);


    }


    int search(vector<int>& nums, int target) {

        int n = nums.size();

        return bin(nums, target, 0, n-1);

        
        
    }
};