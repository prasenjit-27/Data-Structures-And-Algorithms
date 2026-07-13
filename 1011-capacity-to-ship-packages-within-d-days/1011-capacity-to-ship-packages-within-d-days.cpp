class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity) {

        int currWeight = 0;
        int totalDays = 1;

        for (auto i : weights) {

            if (currWeight + i <= capacity) {

                currWeight += i;

            } else {

                totalDays++;
                currWeight = i;
            }
        }

        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int minAns = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(weights, days, mid)) {

                minAns = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return minAns;
    }
};