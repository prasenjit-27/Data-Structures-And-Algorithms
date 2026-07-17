class Solution {
public:
    int solve(int a, int b, int m, int n, vector<vector<int>>& dp) {

        if (a == m - 1 && b == n - 1)
            return 1;
        if (a >= m || b >= n)
            return 0;

        if (dp[a][b] != -1)
            return dp[a][b];

        int right = solve(a, b + 1, m, n, dp);
        int down = solve(a + 1, b, m, n, dp);

        return dp[a][b] = right+down;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, dp);
    }
};