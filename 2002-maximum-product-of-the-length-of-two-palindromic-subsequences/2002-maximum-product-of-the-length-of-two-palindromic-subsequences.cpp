class Solution {
    bool isPalindrome(const string& s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void dfs(int idx, string& s, string& p1, string& p2, int& maxProd) {
        if (idx == s.length()) {
            if (isPalindrome(p1) && isPalindrome(p2)) {
                maxProd = max(maxProd, (int)(p1.length() * p2.length()));
            }
            return;
        }

        p1.push_back(s[idx]);
        dfs(idx + 1, s, p1, p2, maxProd);
        p1.pop_back();

        p2.push_back(s[idx]);
        dfs(idx + 1, s, p1, p2, maxProd);
        p2.pop_back();

        dfs(idx + 1, s, p1, p2, maxProd);
    }

public:
    int maxProduct(string s) {
        int maxProd = 0;
        string p1 = "", p2 = "";
        dfs(0, s, p1, p2, maxProd);
        return maxProd;
    }
};