class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int p1=0;
        int p2=0;
        string fs="";

        while(p1<word1.length() && p2<word2.length())
        {
            fs+=word1[p1++];
            fs+=word2[p2++];
        }
        if(p1<word1.length())
        {
            fs+=word1.substr(p1,word1.length()-p1+1);
        }

        if(p2<word2.length())
        {
            fs+=word2.substr(p2,word2.length()-p2+1);
        }

        return fs;
    }
};