class Solution {
public:
    // int solve(int i, int n, vector<int> &nums,int taken, vector<vector<int>> &dp){
    //     if( i == n ) return 0;
    //     if( dp[i][taken] != -1 ){
    //         return dp[i][taken];
    //     }
    //     int take = INT_MIN;
    //     if(!taken){
    //         take = nums[i]+solve(i+1, n, nums,1,dp);
    //     }
    //     int notTake = solve(i+1,n,nums,0,dp);
    //     return dp[i][taken] = max(take,notTake);
    // }

    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i < 0){
            return 0;
        }
        if(dp[i] != -1 ) return dp[i];
        int take = nums[i]  + solve(i-2,nums,dp);
        int notTake = solve(i-1,nums,dp);
        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = solve(n-1,nums,dp);
        return ans;
        // vector<vector<int>> dp(n,vector<int> (2,-1));
        // int ans = solve(0,n,nums,0,dp);
        // return ans;
        // vector<vector<int>> dp(n, vector<int> (2,0));
        // // dp[i][0] --> Max robbed value while not robbing ith house
        // // dp[i][1] --> Max robbed value while robbing ith house
        // dp[0][0] = 0;
        // dp[0][1] = nums[0];
        // for(int i=1; i<n; i++){
        //     dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        //     dp[i][1] = dp[i-1][0] + nums[i];
        // }
        // return max(dp[n-1][0], dp[n-1][1]);
    }
};