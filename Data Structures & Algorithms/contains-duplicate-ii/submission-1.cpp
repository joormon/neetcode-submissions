class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (right - left > k) {
                st.erase(nums[left]);
                left++;
            }
            if (st.count(nums[right])) {
                return true;
            }
            st.insert(nums[right]);
            right++;
        }
        return false;
    }
};