class Solution {
public:
    int expand(string& s, int left, int right) {

        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }
    string longestPalindrome(string s) {

        int n = s.size();

        if (n <= 1)
            return s;

        int start = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {

            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);

            int len = max(odd, even);

            if (len > maxi) {

                maxi = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxi);
    }
};