class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            int prevSpan=st.top().second;
            span+=prevSpan;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};