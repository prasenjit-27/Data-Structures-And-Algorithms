class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if(target < nums[0]) return 0;

        int n = nums.size();
        int i = 0, j = n-1;

        int val = 0;

        while(i <= j){

            int mid = i + (j-i)/2;

            if(nums[mid] <= target){

                if(nums[mid] == target) return mid;
                else{

                val = mid;
                i = mid+1;
                }

            }else j = mid-1;

        }

        return val + 1;
        
    }
};