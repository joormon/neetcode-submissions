class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n=hand.size();
        if(n%groupSize!=0) return false;

         map<int,int> mp;
        for(int card:hand){
            mp[card]++;
        }


         while(!mp.empty()){
            int x=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(!mp.count(x+i)){
                    return false;
                }

                mp[x+i]--;
                if(mp[x+i]==0) mp.erase(x+i);
            }
        }

        return true;

    }
};
