class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.length()==0) return 0;
        int maxLen=0;
        unordered_set<char> st;
        int right=0;
        int left=0;
        while(right<s.length())
        {
            char c=s[right];
            if(st.count(c))
            {
                while(s[left]!=c)
                {
                    st.erase(s[left]);
                    left++;
                }
                left++;
            }
            maxLen=max(right-left+1,maxLen);
            st.insert(c);
            right++;
        }
        return maxLen;
    }
};
