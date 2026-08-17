class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < n; i++) 
        {

            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            //Have i really processed atleast k elements??
            if(i>=k-1)
            {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
