class Solution {
   public:
    string minWindow(string s, string t) {
        if (!s.length()  || !t.length()) {
            return "";
        }
        unordered_map<char, int> tmap;
        unordered_map<char, int> windowMap;
        int minLength = INT_MAX;
        int startIdx = 0;

        for (char e : t) {
            tmap[e]++;
        }

        int required = t.size();
        int formed = 0;

        int left = 0, right = 0;

        while (right < s.length()) {
            char c = s[right];
            if (tmap.count(c)) {
                windowMap[c]++;
                if (windowMap[c]<=tmap[c]) {
                    formed++;
                }
            }

            while (formed == required) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIdx = left;
                }

                char x = s[left];
                if (tmap.count(x)) {
                    windowMap[x]--;
                    if (windowMap[x] < tmap[x]) {
                        formed--;
                    }
                   
                }
                 left++;
                
            }
            right++;
        }

        return minLength==INT_MAX ? "":s.substr(startIdx, minLength);
    }
};
