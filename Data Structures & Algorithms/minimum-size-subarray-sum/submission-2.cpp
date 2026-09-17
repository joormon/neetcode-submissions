class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left=0;
        int right=0;
        int sum=0;
        int minLen=INT_MAX;
        while(right<nums.size())
        {
            sum+=nums[right];

            while(left<=right && sum>=target)
            {
                minLen=min(right-left+1,minLen);
                sum-=nums[left];
                left++;
            }
            right++;
        }   
        return minLen==INT_MAX?0:minLen;
    }
};