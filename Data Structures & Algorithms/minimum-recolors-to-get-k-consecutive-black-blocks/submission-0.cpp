class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int ops = 0;
        int minOps = INT_MAX;
        int fast = 0;
        int slow = 0;
        int n = blocks.size();
        while (fast < n) {
            if (blocks[fast] == 'W') ops++;
            while (fast - slow + 1 > k) {
                char c = blocks[slow];
                slow++;
                if (c == 'W') {
                    ops--;
                }
            }

            //update the minOps for a valid window ;
            if (fast - slow + 1 == k) {
                minOps = min(minOps, ops);
            }

            fast++;
        }
        return minOps;
    }
};