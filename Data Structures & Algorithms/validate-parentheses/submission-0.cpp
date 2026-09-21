class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty()) {
                if (c == ')' || c == ']' || c == '}')
                    return false;
                else
                    st.push(c);
            } else {
                char tc = st.top();
                if (c == '(' || c == '{' || c == '[')
                    st.push(c);
                else if (c == ')' && tc == '(')
                    st.pop();
                else if (c == ']' && tc == '[')
                    st.pop();
                else if (c == '}' && tc == '{')
                    st.pop();
                else
                    return false;
            }
        }

        if (st.empty()) return true;
        return false;
    }
};
