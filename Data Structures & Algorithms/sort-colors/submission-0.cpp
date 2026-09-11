class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int> cntArray(4,0);

        for(int ele:nums)
        {
            cntArray[ele]++;
        }
        
        //creating prefix sum to maintain the order
        for(int i=1;i<4;i++)
        {
            cntArray[i]=cntArray[i]+cntArray[i-1];
        }

        int n=nums.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            ans[cntArray[nums[i]]-1]=nums[i];
            cntArray[nums[i]]--;
        }

        nums=ans;
    }
};