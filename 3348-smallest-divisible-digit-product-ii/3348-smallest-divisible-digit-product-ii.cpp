class Solution {
private:
    array<int,4> dexp(int d){
        static const array<array<int,4>,10> tbl = {{
            {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
            {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
        }};
        return tbl[d];
    }

    int minCoverAB(int remA,int remB){
        if(remA<=0 && remB<=0) return 0;
        int best = INT_MAX, hi = max(remA,remB)+1;
        for(int t6=0;t6<=hi;t6++){
            int a2=max(0,remA-t6), b2=max(0,remB-t6);
            best = min(best, t6 + (a2+2)/3 + (b2+1)/2);
        }
        return best;
    }

    int minSlots(int A,int B,int C,int D){
        A=max(0,A);B=max(0,B);C=max(0,C);D=max(0,D);
        if(!A&&!B&&!C&&!D) return 0;
        return C + D + minCoverAB(A,B);
    }

    string buildFree(int m,int A,int B,int C,int D){
        string res(m,'1');
        for(int i=0;i<m;i++){
            int rem=m-i-1;
            for(int d=1;d<=9;d++){
                auto e=dexp(d);
                int nA=max(0,A-e[0]),nB=max(0,B-e[1]),nC=max(0,C-e[2]),nD=max(0,D-e[3]);
                if(minSlots(nA,nB,nC,nD)<=rem){ res[i]='0'+d; A=nA;B=nB;C=nC;D=nD; break; }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long tt=t;
        int A=0,B=0,C=0,D=0;
        while(tt%2==0){tt/=2;A++;}
        while(tt%3==0){tt/=3;B++;}
        while(tt%5==0){tt/=5;C++;}
        while(tt%7==0){tt/=7;D++;}
        if(tt!=1) return "-1";

        int n=num.size(), firstZero=n;
        for(int i=0;i<n;i++) if(num[i]=='0'){firstZero=i;break;}

        vector<array<int,4>> pre(n+1,{0,0,0,0});
        for(int i=0;i<n;i++){
            auto e=dexp(num[i]-'0');
            pre[i+1]={pre[i][0]+e[0], pre[i][1]+e[1], pre[i][2]+e[2], pre[i][3]+e[3]};
        }

        // Case 1: num itself already works
        if(firstZero==n){
            int a1=A-pre[n][0], b1=B-pre[n][1], c1=C-pre[n][2], d1=D-pre[n][3];
            if(a1<=0&&b1<=0&&c1<=0&&d1<=0) return num;
        }

        // Case 2: single O(n) scan, rightmost feasible change wins (smallest result)
        int pmax = min(firstZero, n-1);
        for(int p=pmax; p>=0; p--){
            int a1=max(0,A-pre[p][0]), b1=max(0,B-pre[p][1]);
            int c1=max(0,C-pre[p][2]), d1=max(0,D-pre[p][3]);
            int startD=(num[p]-'0')+1; if(startD<1) startD=1;
            int rem=n-p-1;
            for(int d=startD; d<=9; d++){
                auto e=dexp(d);
                int nA=max(0,a1-e[0]),nB=max(0,b1-e[1]),nC=max(0,c1-e[2]),nD=max(0,d1-e[3]);
                if(minSlots(nA,nB,nC,nD)<=rem)
                    return num.substr(0,p)+char('0'+d)+buildFree(rem,nA,nB,nC,nD);
            }
        }

        // Case 3: no same-length answer -> go one digit longer (or more if needed)
        int m=n+1, need=minSlots(A,B,C,D);
        if(m<need) m=need;
        return buildFree(m,A,B,C,D);
    }
};