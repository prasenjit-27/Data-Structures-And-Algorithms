#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    void backtrack(int row, int n, std::unordered_set<int>& cols, std::unordered_set<int>& diag1, std::unordered_set<int>& diag2, std::vector<std::string>& state, std::vector<std::vector<std::string>>& res) {
        if (row == n) {
            res.push_back(state);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            std::string row_str(n, '.');
            row_str[col] = 'Q';
            state.push_back(row_str);
            
            backtrack(row + 1, n, cols, diag1, diag2, state, res);
            
            state.pop_back();
            diag2.erase(row + col);
            diag1.erase(row - col);
            cols.erase(col);
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::unordered_set<int> cols;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;
        std::vector<std::string> state;
        backtrack(0, n, cols, diag1, diag2, state, res);
        return res;
    }
};