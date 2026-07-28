class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        //O(n^2)
        // vector<int> result;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int prod=1;
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if(i!=j)
        //             prod*=nums[j];
        //     }
        //     result.push_back(prod);
        // }
        // return result;

        //O(n)

        int n=nums.size();
        vector<int> result(n,1);
        
        int prefix=1;
        for(int i=0;i<n;i++)
        {
            result[i]=prefix;
            prefix*=nums[i];
        }

        int postfix=1;
        for(int i=n-1;i>=0;i--)
        {
            result[i]*=postfix;
            postfix*=nums[i];
        }

        return result;
    }
};
