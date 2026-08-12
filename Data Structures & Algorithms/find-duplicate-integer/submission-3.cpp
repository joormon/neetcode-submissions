class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow1 = nums[0];
        int fast = nums[0];
        int slow2 = nums[0];

        // Finding the intersection point between fast and slow pointers
        do {
            slow1 = nums[slow1];
            fast = nums[nums[fast]];

        } while (fast != slow1);

            // now we will move both the slow1 and slow2 pointer to find the target
            while (slow1 != slow2) {
            slow1 = nums[slow1];
            slow2 = nums[slow2];
        }

        // so both the pointers are pointing at the target

        return slow1;
    }
};
