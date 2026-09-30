class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                //First check that if you have that 5 dollar change
                if (five <= 0) return false;
                ten++;
                five--;
            } else {
                //Greedy choice taking 10 & 5 keeping the smaller 5 dollar
                //change for future ;
                //because $5 bills are more valuable for handling future $10 customers.
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};