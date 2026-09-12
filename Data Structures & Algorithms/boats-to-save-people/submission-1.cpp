class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size()-1;
        sort(people.begin(), people.end());
        int totalWt = 0;
        int boats = 0;

        while (left<=right) {
            totalWt=people[left]+people[right];
            if(totalWt<=limit)
            {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};