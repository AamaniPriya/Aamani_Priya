class Solution {
public:
    int scoreOfParentheses(string s) {
        int q = 0;
        int p = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                p++;
            }

            if(s[i] == ')') {
                p--;

                if(s[i-1] == '(') {
                    q += (1 << p);
                }
            }
        }

        return q;
    }
};