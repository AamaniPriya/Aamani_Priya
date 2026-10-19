class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int count = 0;

        for (int x : nums) {
            if (x < target)
                smaller++;
            else if (x == target)
                count++;
        }

        vector<int> ans;

        for (int i = smaller; i < smaller + count; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};