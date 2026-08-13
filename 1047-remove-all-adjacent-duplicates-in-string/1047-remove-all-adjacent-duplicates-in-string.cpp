class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size();

        stack<char> st;

        for(auto i: s){

           if(!st.empty() && st.top() == i){

                st.pop();
            }else st.push(i);
        }  

        string ans="";

        while(!st.empty()){

            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;


    }
};