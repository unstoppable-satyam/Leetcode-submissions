class Solution {
private:
    int solve(int i, int j , vector<int> &nums , vector<vector<int>> &dp){
        if( i > j ) return 0;
        if(dp[i][j] != -1 ) return dp[i][j];
        int mx = 0;
        for(int k = i; k<= j ; k++){  // k denotes the index at which we want to burst balloons
            int temp = nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,dp) + solve(k+1,j, nums,dp);
            mx = max( mx,temp);
        } 
        return dp[i][j] = mx;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve( 1,n-2, nums,dp );
    }
};