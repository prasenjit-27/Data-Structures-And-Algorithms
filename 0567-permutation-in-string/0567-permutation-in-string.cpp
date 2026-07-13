class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> x(26, 0), y(26, 0);

        for (auto i : s1) {

            x[i - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < m; j++) {

            y[s2[j] - 'a']++;


            if (j-i + 1 > n) {

                y[s2[i] - 'a']--;
                i++;
            }
            if (j-i + 1 == n) {

                if (x == y)
                    return true;
            }
        }

        return false;
    }
};