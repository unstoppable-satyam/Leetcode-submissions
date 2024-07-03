class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n] =0;
        for(int i = n-1; i>=0 ; i--){
            int mx = INT_MIN;
            int max_ele = arr[i];
            int len = 0;
            for(int ind = i ; ind < min(i+k,n); ind++){
                len++;
                max_ele = max(max_ele,arr[ind]);
                int sum = len*max_ele + dp[ind+1];
                mx = max(mx,sum);
            }
            dp[i]= mx;
        }
        return dp[0];

    }
};