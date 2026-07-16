class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int k, int days) {

        int n = nums.size();

        int count = 0;

        for (int i = 0; i < n; i++) {


            if (nums[i] <= days) {

                count++;
            } else {

                count = 0;
            }

            if (count == k) {

                m--;
                count = 0;
                if (m == 0)
                    return true;
            }


        }

        return false;
    }
    int minDays(vector<int>& nums, int m, int k) {

        int n = nums.size();

        if (1LL * m * k > n)
            return -1;

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(nums, m, k, mid)) {

                ans = mid;
                high = mid - 1;

            } else
                low = mid + 1;
        }

        return ans;
    }
};