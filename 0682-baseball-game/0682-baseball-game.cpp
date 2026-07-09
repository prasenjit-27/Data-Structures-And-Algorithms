class Solution {
public:
    int calPoints(vector<string>& nums) {

        int sum = 0;
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            string val = nums[i];

            if (val == "+") {

                ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
                sum += ans.back();
            } else if (val == "D") {
                ans.push_back((ans[ans.size() - 1] * 2));
                sum += ans.back();
            } else if (val == "C") {
                sum -= ans.back();
                ans.pop_back();
            } else {
                ans.push_back(stoi(val));
                sum += ans.back();
            }
        }

        return sum;
    }
};