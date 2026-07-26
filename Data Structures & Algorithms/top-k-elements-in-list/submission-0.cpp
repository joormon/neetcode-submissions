class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> finallist;
        vector<bool> visited(n,false);
        vector<pair<int,int>> fm; //frequency map {frequeny,element}

        for(int i=0;i<n;i++)
        {
            if(visited[i]) continue;

            int currele=nums[i];
            int freq = 1;
            visited[i]=true;

            for(int j=i+1;j<n;j++)
            {
                if(currele==nums[j])
                {
                    freq++;
                    visited[j]=true;
                }
            }
            fm.push_back(make_pair(freq,currele));
        }

        sort(fm.rbegin(),fm.rend());//sorting in descending order based on first element;

        for(int i=0;i<k;i++)
        {
            finallist.push_back(fm[i].second);
        }

        return finallist;
    }
};
