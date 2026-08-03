class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() { }

    void set(string key, string value, int timestamp) {
        if (mp.find(key) == mp.end()) {
            vector<pair<int, string>> v;
            v.push_back(make_pair(timestamp, value));
            mp[key] = v;
        }
        else
        { 
            mp[key].push_back(make_pair(timestamp,value));
        }
    }

    string get(string key, int timestamp) 
    {
        string ans="";
        if(mp.find(key)!=mp.end())
        {
            vector<pair<int, string>>& v=mp[key];
            for(auto& pair_item : v)
            {
                int time = pair_item.first;
                string value = pair_item.second;
                if(time<=timestamp)
                {
                    ans=value;
                }
            }
        }

        return ans;
    }
};