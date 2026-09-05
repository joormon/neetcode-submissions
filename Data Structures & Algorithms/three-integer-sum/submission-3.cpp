class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int currEle = nums[i];
            if(i>0 && currEle==nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            int val =-1*(currEle);
            while (j < k) {
                if (nums[j] + nums[k] == val) {
                    result.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;

                    j++;
                    k--;
                } else if (nums[j] + nums[k] > val) {
                    k--;
                } else {
                    j++;
                }
                

            }

            
        }

        return result;
    }
};
