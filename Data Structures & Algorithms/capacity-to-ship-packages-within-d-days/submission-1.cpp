class Solution {
 bool canDo(const vector<int>& arr, int& days, int& k) {
        int cap = 0;
        int reqdays = 1;
        int i = 0;
        while (i < arr.size()) {
            if (cap + arr[i] > k) {
                reqdays++;
                cap = 0;
            } 
            cap+=arr[i];
            i++;
        }
        return reqdays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDo(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};