class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int max_count = 0, letter = 0;
        
        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] > max_count) {
                max_count = count[c - 'a'];
                letter = c - 'a';
            }
        }
        
        if (max_count > (s.length() + 1) / 2) return "";
        
        string res = s;
        int idx = 0;
        
        while (count[letter] > 0) {
            res[idx] = 'a' + letter;
            idx += 2;
            count[letter]--;
        }
        
        for (int i = 0; i < 26; ++i) {
            while (count[i] > 0) {
                if (idx >= s.length()) idx = 1;
                res[idx] = 'a' + i;
                idx += 2;
                count[i]--;
            }
        }
        
        return res;
    }
};