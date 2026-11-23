class Solution {
   public:
    int sum(vector<int>& nums) {
        int sum = 0;
        for (int ele : nums) {
            sum += ele;
        }
        return sum;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = sum(nums);
        if (total % 2 != 0) return false;
        int target = total / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < target + 1; j++) {
                bool notpick = dp[i - 1][j];
                bool pick = false;
                if (nums[i] <= j) {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = pick || notpick;
            }
        }

        return dp[n-1][target];
    }
};
