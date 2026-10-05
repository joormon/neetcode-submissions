class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxEnd = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // maxEnd += nums[i];
            // if (maxEnd < 0) {
            //     maxEnd = 0;
            //     sum = 0;
            // } else
            // sum+=nums[i]

                maxEnd=max(nums[i],maxEnd+nums[i]);
                sum =max(sum,maxEnd);
        }

        return sum;
    }
};
