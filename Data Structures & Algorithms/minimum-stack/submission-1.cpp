class MinStack {
    stack<int> st, minst;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minst.push(val);
        } else {
            st.push(val);
            minst.push(min(val, minst.top()));
        }
    }

    void pop() {
        st.pop();
        minst.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minst.top(); }
};
