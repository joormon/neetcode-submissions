class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Brute force taking O(n^2)
        //     int n=nums.size();
        //     vector<int> finallist;
        //     vector<bool> visited(n,false);
        //     vector<pair<int,int>> fm; //frequency map {frequeny,element}

        //     for(int i=0;i<n;i++)
        //     {
        //         if(visited[i]) continue;

        //         int currele=nums[i];
        //         int freq = 1;
        //         visited[i]=true;

        //         for(int j=i+1;j<n;j++)
        //         {
        //             if(currele==nums[j])
        //             {
        //                 freq++;
        //                 visited[j]=true;
        //             }
        //         }
        //         fm.push_back(make_pair(freq,currele));
        //     }

        //     sort(fm.rbegin(),fm.rend());//sorting in descending order based on first element;

        //     for(int i=0;i<k;i++)
        //     {
        //         finallist.push_back(fm[i].second);
        //     }

        //     return finallist;
        // }

        // Optimised approach O(N logk)
        vector<int> finallist;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> count;  //[num,freq]

        // storing the frequency of the numbers
        for (int& num : nums) {
            count[num]++;
        }

        for (auto& [num, freq] : count) {
            minHeap.push(make_pair(freq, num));  // minHeap based on frequency
            if (minHeap.size() > k)
                minHeap.pop();  // we pop the minimum element that is on the top;
        }

        while(!minHeap.empty())
        {
            finallist.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return finallist;
    }
};