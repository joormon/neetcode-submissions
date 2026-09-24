class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxarea = 0;
        for (int i = 0; i <= n; i++) {
            int ele;
            ele= i==n ? 0:heights[i];
            while (!st.empty() && heights[st.top()] > ele) {
                int currh = heights[st.top()];
                int nsi = i;

                //important part start
                st.pop();
                int psi = -1;
                if (!st.empty())
                    psi = st.top();
                //important part end
                
                int w = nsi - psi - 1;
                int area = currh * w;
                maxarea = max(area, maxarea);
            }
            if (i < n)
                st.push(i);
        }

        return maxarea;
    }
};