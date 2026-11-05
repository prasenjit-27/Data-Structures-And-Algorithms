#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = std::max(1, 1 - dungeon[i][j]);
                } else if (i == m - 1) {
                    dp[i][j] = std::max(1, dp[i][j + 1] - dungeon[i][j]);
                } else if (j == n - 1) {
                    dp[i][j] = std::max(1, dp[i + 1][j] - dungeon[i][j]);
                } else {
                    int min_health_on_exit = std::min(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = std::max(1, min_health_on_exit - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};