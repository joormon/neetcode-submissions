class Solution {
public:
    int mySqrt(int x) 
    {
        int l=1;
        int r=x;
        int ans=0;
        while(l<=r)
        {
            long long m=l+(r-l)/2;
            //To tackle overflow:
            //option1: use long long 
            //option2: m*m<=x -> m<=x/m;
            if(m <= x/m)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        } 

        return ans;   
    }
};