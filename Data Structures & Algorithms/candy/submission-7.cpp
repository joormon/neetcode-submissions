class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> LR(n, 1);
        vector<int> RL(n, 1);

        // Left → Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) LR[i] = LR[i - 1] + 1;
        }

        // Right → Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) RL[i] = RL[i + 1] + 1;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += max(LR[i], RL[i]);
        }

        return count;
    }
};