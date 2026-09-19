/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        int l=1;
        int r=n;
        if(guess(1)==0) return 1;
        if(guess(n)==0) return n;

        int ans=n;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(guess(m)==0)
                ans=m;
            
            if(guess(m)<0)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }

        return ans;  
    }
};