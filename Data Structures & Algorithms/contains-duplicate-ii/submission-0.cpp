class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int currIdx=0;
        while(currIdx<nums.size())
        {
            if(mp.count(nums[currIdx]))
            {
                int prevIdx=mp[nums[currIdx]];
                if(abs(currIdx-prevIdx)<=k)
                {
                    return true;
                }
            }

            mp[nums[currIdx]]=currIdx;
            currIdx++;
        }
        return false;   
    }
};