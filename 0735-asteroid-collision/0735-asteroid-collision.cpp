class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {

        int n = nums.size();

        stack<int> st;

        for(auto i: nums){

            while(!st.empty() && i < 0 && st.top() > 0 && st.top() < -i){

                st.pop();
            }

            if(!st.empty()&& i < 0 && st.top() > 0){

                if(!st.empty() && st.top() == - i){

                    st.pop();
                }

                


            }else{

                st.push(i);
            }
        }

        vector<int> ans(st.size(),0);

        for(int i = st.size()-1; i>=0; i--){

            ans[i] = st.top();
            st.pop();
        }

        return ans;
        
    }
};