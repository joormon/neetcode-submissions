class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encoded_string;
        for(string& str:strs)
        {
            int length=str.length();
            encoded_string+=to_string(length)+"#"+str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) 
    {
        int i=0;
        int n=s.length();
        vector<string> decodedStrings;

        while(i<n)
        {
            int delimiterPos = s.find("#",i);//find the position of # from i 
            int length = stoi(s.substr(i,delimiterPos-i));
            
            string str=s.substr(delimiterPos+1,length);
            decodedStrings.push_back(str);

            i=delimiterPos+1+length;
        }

        return decodedStrings;
    }
};
