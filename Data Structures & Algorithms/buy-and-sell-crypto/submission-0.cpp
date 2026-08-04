class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit=0;
        int left=0;//left cover of window;
        int right=0;
        int currProfit;
        while(left<=right && right<prices.size())
        {
            if(prices[right]<prices[left])
            {
                left=right;
            }
            currProfit=prices[right]-prices[left];
            maxProfit=max(currProfit,maxProfit);
            right=right+1;
        }

        return maxProfit;
    }
};
