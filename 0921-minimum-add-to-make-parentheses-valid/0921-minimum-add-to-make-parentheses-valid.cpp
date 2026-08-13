class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int closing = 0;

        for (auto i : s) {

            if (!st.empty() && st.top() == '(' and i == ')') {

                st.pop();
            } else if (i == ')')
                closing++;
            else
                st.push(i);
        }

        return closing + st.size();
    }
};