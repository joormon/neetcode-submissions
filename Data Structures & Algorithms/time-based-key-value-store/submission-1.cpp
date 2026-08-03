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

    string binarySearch(vector<pair<int,string>>& v,int timestamp)
    {
        int left=0;
        int right=v.size()-1;
        string ans="";
        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(v[mid].first<=timestamp)
            {
                ans=v[mid].second;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return ans;
    }

    string get(string key, int timestamp) 
    {
        string ans="";
        if(mp.find(key)!=mp.end())
        {
            vector<pair<int, string>>& v=mp[key];
            ans=binarySearch(v,timestamp);
            // for(auto& pair_item : v)
            // {
            //     int time = pair_item.first;
            //     string value = pair_item.second;
            //     if(time<=timestamp)
            //     {
            //         ans=value;
            //     }
            // }
        }
        return ans;
    }
};