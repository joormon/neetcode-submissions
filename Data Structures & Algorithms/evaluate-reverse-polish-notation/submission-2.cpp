class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string ele : tokens) {
            if (ele == "*") {
               int result = 1;
                int count = 0;
                while (!st.empty() && count < 2) {
                    result *= st.top();
                    st.pop();
                    count++;
                }
                st.push(result);
            } else if (ele == "+") {
               int result = 0;
                int count = 0;
                while (!st.empty() && count < 2) {
                    result += st.top();
                    st.pop();
                    count++;
                }
                st.push(result);
            } else if (ele == "-") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
            } else if (ele == "/") {
                int divisor = st.top();
                st.pop();
                int dividend = st.top();
                st.pop();
                st.push(dividend / divisor);
            } else
                st.push(stoi(ele));
        }

        int output=st.top();
        st.pop();
        return output;
    }
};
