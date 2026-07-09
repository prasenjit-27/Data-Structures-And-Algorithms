class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        if (k > n)
            return {};

        vector<int> ans;

        vector<int> pcount(26, 0);
        vector<int> scount(26, 0);

        for (int i = 0; i < k; i++) {

            pcount[p[i] - 'a']++;
            scount[s[i] - 'a']++;
        }

        if (pcount == scount)
            ans.push_back(0);

        for (int i = k; i < n; i++) {

            scount[s[i] - 'a']++;

            scount[s[i - k] - 'a']--;

            if (scount == pcount)
                ans.push_back(i-k+1);
        }

        return ans;
    }
};