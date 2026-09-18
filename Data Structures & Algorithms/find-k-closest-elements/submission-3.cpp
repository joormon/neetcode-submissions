class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (abs(x - arr[idx]) > abs(x - arr[i])) {
                idx = i;
            }
        }

        vector<int> result;
        result.push_back(arr[idx]);
        int left = idx - 1;
        int right = idx + 1;
        while (result.size() < k) {
            if (left >= 0 && right < arr.size()) {
                result.push_back(abs(arr[left] - x) <= abs(arr[right] - x) ? arr[left--]
                                                                           : arr[right++]);
            } else if (left >= 0) {
                result.push_back(arr[left--]);
            } else {
                result.push_back(arr[right++]);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};