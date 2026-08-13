class Solution {
public:
    int minLength(string s) {

        stack<int> st;

        for(auto i: s){

            if(!st.empty() && (st.top() == 'A' && i == 'B' || st.top() == 'C' && i == 'D' )){

                st.pop();
            }else st.push(i);
        }

        return st.size();


        
    }
};