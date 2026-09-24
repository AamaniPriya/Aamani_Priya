class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                sum++;
            }
            else {
                ans.push_back(sum);
                sum = 0;
            }
        }

        ans.push_back(sum);

        int m = 0;

        for(int i = 0; i < ans.size(); i++) {
            m = max(m, ans[i]);
        }

        return m;
    }
};