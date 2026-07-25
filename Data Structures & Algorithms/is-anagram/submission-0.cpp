class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //BRUTE FORCE
        // if(s.length()!=t.length())
        //     return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // return s==t;

        //Optimised
        vector<int> count(26,0);
        if(s.length()!=t.length())
            return false;
            
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(int num:count)
        {
            if(num!=0)
                return false;
        }

        return true;
    }
};
