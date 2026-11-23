class Solution {
   public:
   //optimised spaced to O(target)
    int sum(vector<int>& nums) {
        int sum = 0;
        for (int ele : nums) {
            sum += ele;
        }
        return sum;
    }
    bool canPartition(vector<int>& nums) {
        int total=sum(nums);
        if(total%2!=0) return false;
        int target=total/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;

        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j]||dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};
