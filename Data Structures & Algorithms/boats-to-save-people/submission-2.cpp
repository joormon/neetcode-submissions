class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size()-1;
        sort(people.begin(), people.end());
        int boats = 0;

        while (left<=right) {
            if(people[left]+people[right]<=limit)
            {
                left++;
            }
            //Greedy approach: we are taking the heavy person first;
            right--;
            boats++;
        }
        return boats;
    }
};