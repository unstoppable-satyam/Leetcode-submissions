class Solution {
public:
    bool check(int i, int k, vector<int> &arr, vector<vector<int>> &dp ){
        if(k == 0 ) return true;
        if(i < 0 ) return false;
        if(dp[i][k] != -1 ) return dp[i][k];
        bool notTake = check(i-1,k,arr,dp);
        bool take = false;
        if(arr[i] <= k){
            take = check(i-1,k-arr[i],arr,dp);
        }
        return dp[i][k] = take|notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum= 0;
        for(int i= 0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 == 1 ) return false;
        vector<vector<int>> dp(n, vector<int> ( sum/2+1,-1));
        return check(n-1,sum/2,nums,dp);
    }
};