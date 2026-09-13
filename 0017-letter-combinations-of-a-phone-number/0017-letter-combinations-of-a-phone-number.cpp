class Solution {
public:
    vector<string> ans;
    
    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int index, string current) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string chars = letters[digits[index] - '0'];

        for (char ch : chars) {
            current.push_back(ch);
            solve(digits, index + 1, current);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        solve(digits, 0, "");
        return ans;
    }
};