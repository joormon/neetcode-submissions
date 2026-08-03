class Solution {
public:

    bool canKokoEat(vector<int>& piles,int h,int mid)
    {
        int totalHrs=0;
        for(int& pile:piles)
        {
            totalHrs+=(pile+mid-1)/mid;
        }

        return totalHrs<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int k;
        int maxpile=0;

        for(int & pile:piles)
        {
            maxpile=max(pile,maxpile); 
        }

        int left=1;
        int right=maxpile;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(canKokoEat(piles,h,mid))
            {
                k=mid;//mid is the possible minimum value;
                right=mid-1;//check for minimum value less than mid
            }
            else//Koko cannot finish the piles of bananas in time
            {
                left=mid+1;
            }
        }

        return k;
    }
};
