class Solution {
public:
    int counterExpand(string& s, int left, int right) {

        int n = s.size();
        int count = 0;

        while (left >= 0 && right < n && s[left] == s[right]) {

            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int n = s.size();

        if (n <= 0)
            return 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int odd = counterExpand(s, i, i);
            int even = counterExpand(s, i, i + 1);

            ans += odd;
            ans += even;
        }

        return ans;
    }
};