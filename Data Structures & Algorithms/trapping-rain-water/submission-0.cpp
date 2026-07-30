class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        vector<int> capacity(n,0);
        int MaxCap=0;

        //storing the max left for each position
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(height[i-1],leftMax[i-1]);
        }
        //storing the right max for each position
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(height[i+1],rightMax[i+1]);
        }

        //storing the minimum capcity at each position
        for(int i=0;i<n;i++)
        {
            int currCap=min(leftMax[i],rightMax[i])-height[i];
            if(currCap<=0)
                continue;
            else
                capacity[i]=currCap;
        }

        for(int& cap:capacity)
        {
            MaxCap+=cap;
        }

        return MaxCap;

    }
};
