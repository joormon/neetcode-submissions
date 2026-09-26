class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string part;
        vector<string> simplified;
        string result;

        while (getline(ss, part, '/')) {
            if (part == "" || part==".") {
                continue;
            } else if (part == "..") {
                if (!simplified.empty()) simplified.pop_back();
            } else {
                simplified.push_back(part);
            }
        }

        if(simplified.empty()) return "/";

        for(string token:simplified){
            result+="/"+token;
        }

        return result;
    }
};