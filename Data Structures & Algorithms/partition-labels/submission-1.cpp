class Solution {
    int lastOccur(int idx,string s,char c){
        int ans;
        for(int i=idx;i<s.length();i++){
            if(s[i]==c){
                ans=i;
            }
        }

        return ans;
    }
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> result;
        int end=0;
        int start=0;
        for(int i=0;i<n;i++){
            int idx=lastOccur(i,s,s[i]);
            if(idx>end){
                end=idx;
            }
            if(i==end){
                result.push_back(end-start+1);
                start=end+1;
            }
        }

        return result;
    }
};
