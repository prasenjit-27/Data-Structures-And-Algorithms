class Solution {
public:
    int calPoints(vector<string>& nums) {

        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            string val = nums[i];

            if (val == "+") {

                ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
            } else if (val == "D") {
                ans.push_back((ans[ans.size() - 1] * 2));
            } else if (val == "C") {
                ans.pop_back();
            } else {
                ans.push_back(stoi(val));
            }
        }

        int sum = 0;

        for(int i: ans) sum += i;

        return sum;
    }
};