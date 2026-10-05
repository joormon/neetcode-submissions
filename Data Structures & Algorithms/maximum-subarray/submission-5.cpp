class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxEnd = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            
            if (maxEnd < 0) {
                maxEnd = nums[i];
                sum = max(sum,maxEnd);
            }else{
                maxEnd+=nums[i];
                sum=max(sum,maxEnd);
            }
        }

        return sum;
    }
};
