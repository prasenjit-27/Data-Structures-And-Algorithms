class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {


        int n = nums.size();

        stack<int> st;

        vector<int> ans(n,-1);


        for(int i= n*2 - 1; i>= 0; i--){

            int idx = i%n;

            while(!st.empty() && st.top() <= nums[idx]){

                st.pop();
            }

            if(idx < n && !st.empty()){

                ans[idx] = st.top();


            }

            st.push(nums[idx]);
        }

        return ans;
        
    }
};