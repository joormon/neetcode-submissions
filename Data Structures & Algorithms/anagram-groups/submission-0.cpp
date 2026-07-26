class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //Brute Force ->O(N^2 klogk)
        // int n = strs.size();
        // vector<bool> verify(n, false);
        // vector<vector<string>> finallist;

        // for (int i = 0; i < n; i++) {
        //     vector<string> sublist;
        //     if (!verify[i]) {
        //         sublist.push_back(strs[i]);
        //         verify[i] = true;
        //         string s = strs[i];
        //         sort(s.begin(), s.end());
        //         for (int j = i + 1; j < n; j++) {
        //             if (!verify[j]) {
        //                 string t = strs[j];
        //                 sort(t.begin(),t.end());
        //                 if (s == t)
        //                 {
        //                     sublist.push_back(strs[j]);
        //                     verify[j]=true;
        //                 } 
        //             }
        //         }
        //         finallist.push_back(sublist);
        //     }
        // }

        // return finallist;

        //ANOTHER APPROACH using Hash Map TC:O(N klogk)
        vector<vector<string>> finallist;
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
        {
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }

        for(const pair<string,vector<string>>& p:mp)
        {
            finallist.push_back(p.second);
        }

        return finallist;
    }
};
