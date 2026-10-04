class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        for (int num : s) {
            // If num - 1 exists, then num is not the beginning of the sequence, so don't expand
            // from here.
            if (s.count(num - 1)) continue;
            int current = num;
            int length = 1;
            while (s.count(current + 1)) {
                current++;
                length++;
            }
            ans = max(ans, length);
        }

        return ans;
    }
};
