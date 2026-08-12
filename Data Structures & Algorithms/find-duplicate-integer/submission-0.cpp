class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // O(nlogn)

        int ans = 0;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int prev = nums[0];
        for (int curr = 1; curr < n; curr++) {
            if (prev == nums[curr]) {
                ans = nums[curr];
                break;
            }

            prev=nums[curr];
        }

        return ans;
    }
};
