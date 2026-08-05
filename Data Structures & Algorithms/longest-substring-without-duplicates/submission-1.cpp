class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0;
        int right=0;
        int maxlen=0;
        //unordered_map<char,int> freq;
        vector<int> lastSeen(256,-1);//storing the last seen index;
        while(right<s.length())
        {
            unsigned char curr=s[right];
            if(lastSeen[curr]>=left)
            {
                left=lastSeen[curr]+1;
            }

            lastSeen[curr]=right;
            maxlen=max(maxlen,right-left+1);
            right++;
        }

        return maxlen;
    }
};