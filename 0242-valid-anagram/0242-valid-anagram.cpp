class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> arr(26,0);

        for(int i = 0; i<t.size(); i++){

            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        

        for(int i =0; i<arr.size(); i++){

            if(arr[i] != 0) return false;
        }

        return true;
    }
};