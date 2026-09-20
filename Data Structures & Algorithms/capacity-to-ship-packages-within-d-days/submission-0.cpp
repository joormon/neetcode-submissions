class Solution 
{
    int sum(const vector<int>& arr)
    {
        int sum=0;
        for(int ele:arr)
        {
            sum+=ele;
        }
        return sum;
    }

    bool canDo(const vector<int>& arr,int& days,int& k)
    {
        int cap=0;
        int reqdays=0;
        int i=0;
        while(i<arr.size())
        {
            if(cap+arr[i]>k)
            {
                reqdays++;
                cap=0;
            }
            else
            {
                cap+=arr[i];
                i++;
            }
        }
        if(cap<=k) reqdays++;

        return reqdays<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left=*max_element(weights.begin(),weights.end());
        int right=sum(weights);
        int ans;
        while(left<=right)
        {   
            int mid=left+(right-left)/2;
            if(canDo(weights,days,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return ans;           
    }
};