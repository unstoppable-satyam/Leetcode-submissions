class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);   // boundary before start
        int ans = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();  // try to match with last '('

                if (st.empty()) {
                    // no valid starting point, so this ')' becomes new boundary
                    st.push(i);
                } else {
                    // valid substring ends at i
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;

    }
};