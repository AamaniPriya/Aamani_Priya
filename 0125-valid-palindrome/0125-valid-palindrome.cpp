class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        // Keep only letters and numbers
        for (char c : s) {
            if (isalnum(c)) {
                t += tolower(c);
            }
        }

        // Check palindrome
        string rev = t;
        reverse(rev.begin(), rev.end());

        return t == rev;
    }
};