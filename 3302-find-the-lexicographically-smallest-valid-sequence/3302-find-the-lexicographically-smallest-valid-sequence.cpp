class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m, -1);
        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
        }

        vector<int> ans;
        int p = 0;
        bool used = false;

        for (int i = 0; i < m; i++) {
            while (p < n) {
                if (word1[p] == word2[i]) {
                    ans.push_back(p);
                    p++;
                    break;
                }

                if (!used) {
                    if (i == m - 1 || (suf[i + 1] != -1 && suf[i + 1] > p)) {
                        ans.push_back(p);
                        p++;
                        used = true;
                        break;
                    }
                }

                p++;
            }

            if (ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};