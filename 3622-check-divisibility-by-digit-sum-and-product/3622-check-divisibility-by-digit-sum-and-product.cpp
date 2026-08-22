class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int ps_sum;
        int sum=0;
        int product=1;
        int d;
        while(n>0){
            d=n%10;
            sum+=d;
            product*=d;
            n=n/10;
        }
        ps_sum=sum+product;
        if(num%ps_sum==0){
            return true;
        }
        else{
            return false;
        }
    }
};