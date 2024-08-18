class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int p1 = 1 , p2 = 1 , p3 = 1;
        for(int i= 2 ; i<= n; i++){
            int twoMul = 2*dp[p1];
            int threeMul = 3*dp[p2];
            int fiveMul = 5*dp[p3];
            int mn =min(twoMul,min(threeMul, fiveMul));
            dp[i] = mn;
            if( dp[i] == twoMul ) p1++;
            if( dp[i] == threeMul ) p2++;
            if( dp[i] == fiveMul ) p3++;
        }
        return dp[n];
    }
};