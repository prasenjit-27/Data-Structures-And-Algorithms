class Solution {
public:
    bool isPossible(vector<int>& piles, int hours, int speed) {

        long long total = 0;

        for (int i = 0; i < piles.size(); i++) {

            total += piles[i] / speed;

            if (piles[i] % speed) {

                total += 1;
            }
        }

        return total <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = INT_MIN;

        for (auto i : piles)high = max(high, i);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {

                low = mid + 1;
            }
        }

        return ans;
    }
};