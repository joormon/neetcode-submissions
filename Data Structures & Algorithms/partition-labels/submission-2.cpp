class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> lastOccur(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            lastOccur[s[i]-'a']=i;
        }

        int end=0;
        int start=0;

        for(int i=0;i<n;i++){
            if(lastOccur[s[i]-'a']>end){
                end=lastOccur[s[i]-'a'];
            }

            if(i==end){
                result.push_back(end-start+1);
                start=end+1;
            }
        }

        return result;
    }
};
