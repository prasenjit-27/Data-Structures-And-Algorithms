class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed) {

        double total = 0.0;

        int n = dist.size();

        for (int i = 0; i < n - 1; i++)
            total += ceil(dist[i] / double(speed));

        total += dist[n - 1] / double(speed);

        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int n = dist.size();

        if (hour <= n - 1)
            return -1;

        int low = 1;
        int high = 1e7;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(dist, hour, mid)) {

                ans = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return ans;
    }
};