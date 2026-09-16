class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()==0) return 0;
        vector<int> freq(256);
        int duplicates=0;
        int left=0;
        int right=0;

        while(right<s.length())
        {
            char inChar=s[right];
            freq[inChar]++;

            if(freq[inChar]>1)
            {
                duplicates++;
            }

            if(duplicates>0)
            {
                char oChar=s[left];
                if(freq[oChar]>1)
                {
                    duplicates--;
                }
                freq[oChar]--;
                left++;
            }

            right++;
        }

        return right-left;
    }
};
