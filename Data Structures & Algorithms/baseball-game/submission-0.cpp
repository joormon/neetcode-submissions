class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for (string ops : operations) {
            if (st.empty()) {
                if (ops == "C" || ops == "D" || ops == "+")
                    return 0;
                else
                    st.push(stoi(ops));
            } else {
                if (ops == "C") {
                    st.pop();
                } else if (ops == "D") {
                    int top = st.top();
                    st.push(2 * top);
                } else if (ops == "+") {
                    if (st.size() == 1) return 0;
                    int top = st.top();
                    st.pop();
                    int top_prev = st.top();
                    st.push(top);
                    st.push(top + top_prev);
                } else {
                    st.push(stoi(ops));
                }
            }
        }

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};