class Solution {
    struct vectorHash{
        size_t operator()(const vector<int>& v)const{
            size_t hash=0;

            for(int x:v){
              hash=hash*10+x;
            }

            return hash;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<vector<int>,vector<string>,vectorHash> mp;//string,index;
        for(string str:strs){
            vector<int> freq(26);
            for(char c:str){
                freq[c-'a']++;
            }

            if(mp.count(freq)){
                mp[freq].push_back(str);
            }else{
                mp[freq]={str};
            }
        }

        for(auto [m,l]:mp){
            result.push_back(l);
        }   
        
        return result;
    }
};
