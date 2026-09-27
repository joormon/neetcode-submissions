class Solution {
   public:
    string decodeString(string s) {
        stack<int> count;           // to join the current string count times
        stack<string> prev_contxt;  // to remember the prev context or string
        string current_string = "";
        int num = 0;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                prev_contxt.push(current_string);
                count.push(num);
                current_string = "";
                num = 0;
            } else if (c == ']') {
                int num = count.top();
                count.pop();
                string temp = "";
                while (num > 0) {
                    temp += current_string;
                    num--;
                }
                temp = prev_contxt.top() + temp;
                current_string = temp;
                prev_contxt.pop();
            } else {
                current_string += c;
            }
        }

        return current_string;
    }
};