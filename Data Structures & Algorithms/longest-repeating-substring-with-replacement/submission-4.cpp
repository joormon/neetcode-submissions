class Solution {
   public:
    int characterReplacement(string s, int k) 
    {
       int maxlen=0;
        int left=0;
        int right=0;
        vector<int> freq(26,0);
        int maxfreq=0;
        int windowLength=0;
        while(right<s.length())
        {
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            windowLength=right-left+1;

            if(windowLength-maxfreq > k)
            {
                freq[s[left]-'A']--;
                left=left+1;
            }
            else
            {
                maxlen=max(maxlen,windowLength);
            }
            right=right+1;
        }
        return maxlen;
    }
};
