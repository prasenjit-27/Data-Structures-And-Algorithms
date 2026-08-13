class Solution {
public:
    string makeGood(string s) {

        stack<char> st;

        for(auto i: s){

            if(!st.empty() && tolower(st.top()) == tolower(i) && st.top() != i){

                 st.pop();
            }else{

                st.push(i);
            }
        }

        string ans = "";

        while(!st.empty()){

            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;


        
    }
};