class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int right = 1;
        int left = 0;
        int n = nums.size();

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