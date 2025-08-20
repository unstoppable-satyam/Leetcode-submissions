class Solution {
public:
    int ways(int i, vector<int>& dp) {
        if (i < 0)
            return 0;
        if (i == 0)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = (ways(i - 1, dp) + ways(i - 2, dp));
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return ways(n,dp);
        if(n <=1 ) return 1;
        int prev1 = 1,prev2 =1; 
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};