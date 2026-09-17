class Solution 
{ 
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int minLen=INT_MAX;
        unordered_set<int> st;
        st.reserve(min((int)nums.size(),k+1));
        for(int i=0;i<nums.size();i++)
        {
            if(i>k)
            {
                st.erase(nums[i-k-1]);
            }
            if(!st.insert(nums[i]).second)
            {
                return true;
            }
        } 
        return false;   
    }
};