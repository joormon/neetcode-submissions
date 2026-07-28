class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        //      O(N logN)
        //     int i = 0;
        //     int maxlength = 1;
        //     int n = nums.size();
        //     int currlen = 1;

        //     if (n == 0) return 0;

        //     sort(nums.begin(), nums.end());
        //     while (i < n - 1) {
        //         //for duplicates
        //         if (nums[i + 1] == nums[i]) {
        //             i++;
        //             continue;
        //         }
        //         if (nums[i + 1] == nums[i] + 1) {
        //             currlen = currlen + 1;
        //             maxlength = max(maxlength, currlen);
        //         } else {
        //             currlen = 1;
        //         }
        //         i++;
        //     }

        //     return maxlength;
        // }

        // O(N) time complexity

        int n = nums.size();
        if (n == 0) return 0;

        int maxlen = 1;
        unordered_set<int> s;
        int startingNum;
        s.insert(nums.begin(), nums.end());

        for (int& num : nums) {
            if (s.find(num - 1) == s.end()) {
                int currNum = num;
                int currstreak = 1;

                while (s.find(currNum + 1) != s.end()) {
                    currNum += 1;
                    currstreak += 1;
                }
                maxlen = max(currstreak, maxlen);
            }
        }

        return maxlen;
    }
};
