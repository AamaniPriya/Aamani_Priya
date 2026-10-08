class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for(char c : s) {
            if(c == '(') {
                count++;
                if(count > 1)
                    ans += c;
            }
            else {
                count--;
                if(count > 0)
                    ans += c;
            }
        }

        return ans;
    }
};