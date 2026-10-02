class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> LR(n,1);
        vector<int> RL(n,1);

        for(int i=1,j=n-2;i<n && j>=0;i++,j--){
            if(ratings[i]>ratings[i-1]) LR[i]+=LR[i-1];
            if(ratings[j]>ratings[j+1]) RL[j]+=RL[j+1];
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            count+=max(LR[i],RL[i]);
        }

        return count;
    }
};