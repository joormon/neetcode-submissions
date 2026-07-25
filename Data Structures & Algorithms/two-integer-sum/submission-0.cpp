class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //Brute force -->TC:O(n^2)
        // for(int i =0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j] == target)
        //             return {i,j};
        //     }
        // }

        // return {};

        //Optimized using hash map 
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(m.find(complement)!=m.end())
            {
                return {m[complement],i};
            }

            m[nums[i]]=i;
        }

        return {};
    }
};
