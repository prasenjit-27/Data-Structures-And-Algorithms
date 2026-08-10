class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;

        int n= nums1.size();
        int m = nums2.size();

        vector<int> ans(n,-1);

        for(int i = m-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums2[i]){

                st.pop();
            }

            for(int j= 0; j<n; j++){

                if(nums2[i] == nums1[j]){

                    if(!st.empty()){

                        ans[j] = st.top();
                    }
                    break;
                }
            }

            st.push(nums2[i]);
        }

        return ans;
        
    }
};