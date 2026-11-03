class Solution {
public:
    int minMoves(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int c=0;
        int b=0;
        int k;
        for (int x:nums){
            while(x!=a){
                x++;
                b++;
            }
            
        }
        return b;
    }
};