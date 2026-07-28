class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int i = 0;
        int maxlength = 1;
        int n = nums.size();
        int currlen = 1;

        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        while (i < n - 1) {
            //for duplicates
            if (nums[i + 1] == nums[i]) {
                i++;
                continue;
            }
            if (nums[i + 1] == nums[i] + 1) {
                currlen = currlen + 1;
                maxlength = max(maxlength, currlen);
            } else {
                currlen = 1;
            }
            i++;
        }

        return maxlength;
    }
};
