class MinStack {
    stack<long long> st;
    long long min;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min = val;
        } else if (val < min) {
            // value is less than the minimum so far
            // store the encoded value
            st.push(2LL * val - min);
            min = val;
        } else {
            st.push(val);
        }
    }

    void pop() {
        // if top value is less than the curr min
        // then its an encoded value
        // find the oldmin
        if (st.top() < min) {
            long long oldmin = 2LL * min - st.top();
            min = oldmin;
        }
        st.pop();
    }

    int top() {
        // this means top value is the minimum value itself
        if (st.top() < min) {
            return min;
        }
        return st.top();
    }

    int getMin() { return min; }
};
