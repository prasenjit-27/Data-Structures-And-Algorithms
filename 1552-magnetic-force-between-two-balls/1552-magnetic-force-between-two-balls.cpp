class Solution {
public:
    bool isPossible(vector<int>& nums, int balls, int force) {

        int n = nums.size();

        int count = 1;
        int lastOne = nums[0];

        for (int i = 0; i < n; i++) {

            if (abs(nums[i] - lastOne) >= force) {

                count++;
                lastOne = nums[i];
            }
        }

        return count >= balls;
    }
    int maxDistance(vector<int>& nums, int balls) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 1;

        int high = nums[n - 1] - nums[0];

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(nums, balls, mid)) {

                ans = mid;
                low = mid + 1;

            } else
                high = mid - 1;
        }

        return ans;
    }
};