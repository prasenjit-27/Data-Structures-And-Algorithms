class Solution {
    void backtrack(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        if (n == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }
        if (n < 0 || current.size() > k) {
            return;
        }
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(k, n - i, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n, 1, current, result);
        return result;
    }
};