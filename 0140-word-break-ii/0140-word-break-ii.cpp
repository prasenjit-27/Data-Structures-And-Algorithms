class Solution {
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& wordDict) {
        if (memo.count(s)) return memo[s];
        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        for (const string& word : wordDict) {
            if (s.substr(0, word.length()) == word) {
                vector<string> subList = dfs(s.substr(word.length()), wordDict);
                for (const string& sub : subList) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        return memo[s] = result;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};