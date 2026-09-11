class Solution {
public:
    //performed Counting Sort;
    void sortColors(vector<int>& nums) 
    {
        vector<int> cntArray(3);

        for(int ele:nums)
        {
            cntArray[ele]++;
        }

        int idx=0;
        for(int i=0;i<3;i++)
        {
            while(cntArray[i]>0)
            {
                nums[idx++]=i;
                cntArray[i]--;
            }
        }
    }
};