class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        //Brute force-> O(N^2)
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

    //     int maxCap=0;
    //     int left=0;
    //     int right=heights.size()-1;

    //     while(left<right)
    //     {
    //         int minheight=min(heights[left],heights[right]);
    //         int width=right-left;
    //         int currcap=minheight * width;

    //         maxCap=max(currcap,maxCap);

    //         if(heights[left]<heights[right])//left height is minimum;
    //         {
    //             left++;
    //         }
    //         else
    //         {
    //             right--;
    //         }
    //     }

    //     return maxCap;

    // }
};
