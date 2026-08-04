class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0;
        int right=0;
        int maxlen=0;
        unordered_map<char,int> freq;
        while(right<s.length())
        {
            freq[s[right]]++;
            while(freq[s[right]]>1 && right>=left)
            {
                freq[s[left]]--;
                left=left+1;
            }

            maxlen=max(maxlen,right-left+1);
            right=right+1;
        }

        return maxlen;
    }
};