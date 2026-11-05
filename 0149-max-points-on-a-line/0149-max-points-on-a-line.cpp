class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int max_points = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_map;
            int duplicates = 1;
            int local_max = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                string slope_key = to_string(dx) + "_" + to_string(dy);
                slope_map[slope_key]++;
                local_max = max(local_max, slope_map[slope_key]);
            }
            max_points = max(max_points, local_max + duplicates);
        }
        return max_points;
    }
};