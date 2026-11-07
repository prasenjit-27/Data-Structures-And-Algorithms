class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int min_total = INT_MAX;
        
        for (int r = 0; r < n; ++r) {
            int current_cost = r;
            for (int i = 0; i < n / 2; ++i) {
                char left_char = s[(i + r) % n];
                char right_char = s[(n - 1 - i + r) % n];
                int diff = abs(left_char - right_char);
                current_cost += min(diff, 26 - diff);
            }
            min_total = min(min_total, current_cost);
        }
        
        return min_total;
    }
};