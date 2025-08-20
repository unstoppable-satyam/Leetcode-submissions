class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 1;
        if(dp[i][j] != -1 ) return dp[i][j];
        return dp[i][j]= solve(i-1,j,dp) + solve(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        long long ans = 1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
        // vector<vector<int>> dp(m,vector<int> (n,1));
        
        // for(int i = 1; i<n; i++){
        //     for(int j= 1;j<m; j++){
        //         dp[j][i] = (dp[j-1][i] + dp[j][i-1]);
        //     }
        // }
        // return dp[m-1][n-1];
    }
};