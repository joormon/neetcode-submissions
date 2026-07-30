class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        //Brute force
        int maxcapacity=0;
        int n=heights.size();

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int minheight=min(heights[i],heights[j]);
                int width=j-i;
                int currcapacity=minheight * width;

                maxcapacity=max(currcapacity,maxcapacity);
            }
        }

        return maxcapacity;
    }
};
