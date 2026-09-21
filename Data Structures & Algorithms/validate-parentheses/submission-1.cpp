class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;
                char tc = st.top();
                if ((c ==')' && tc == '(') || (c == ']' && tc == '[') || (c == '}' && tc == '{')) {
                    st.pop();
                } else
                    return false;
            }
        }

        return st.empty();
    }
};
