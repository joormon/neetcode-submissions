class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int right = 1;
        int left = 0;
        int n = nums.size();
        int duplicates = 0;

        while (right < n) {
           
            if(nums[left]!=nums[right])
            {
                left++;
            }
            nums[left]=nums[right];
            right++;
        }

        return left+1;
    }
};