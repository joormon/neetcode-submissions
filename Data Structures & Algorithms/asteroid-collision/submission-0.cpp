class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int inc_ast=asteroids[i];
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && inc_ast<0){
               if(st.top()>-inc_ast){
                    destroyed=true;
                    break;
               }else if(st.top()== -inc_ast){
                    st.pop();
                    destroyed=true;
                    break;
               }else{
                    st.pop();
               }
            }
            
            if(!destroyed) st.push(inc_ast);
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};