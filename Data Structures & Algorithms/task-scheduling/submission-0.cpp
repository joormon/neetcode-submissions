class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26 ;i++){
            if(freq[i]){
                pq.push({freq[i],'A'+i});
            }
        }

        queue<tuple<int,int,char>> cooldown;
        int time=0;

        while(!pq.empty() || !cooldown.empty()){

            while(!cooldown.empty() && get<1>(cooldown.front())<=time){
                auto [count,availableTime,task]=cooldown.front();
                cooldown.pop();
                pq.push({count,task});
            }

            if(!pq.empty()){
                auto [count,task]=pq.top();
                pq.pop();
                count--;

                if(count>0){
                    cooldown.push({count,time+n+1,task});
                }
            }

            time++;
        }


        return time;
    }
};
