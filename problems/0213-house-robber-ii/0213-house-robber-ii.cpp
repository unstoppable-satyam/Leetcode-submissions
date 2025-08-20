class Solution {
public:
    int solve(int i,int taken_last, vector<int> &nums, vector<int> &dp){
        if(taken_last && i<= 0) return 0;
         if(i < 0){
            return 0;
        }
        if(dp[i] != -1 ) return dp[i];
        int take = nums[i]  + solve(i-2,taken_last,nums,dp);
        int notTake = solve(i-1,taken_last,nums,dp);
        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,-1);
        int leave_last = solve(n-2,0,nums,dp1);
        vector<int> dp2(n,-1);
        int take_last = nums[n-1] + solve(n-3,1,nums,dp2);
        return max(leave_last, take_last);

    }
};