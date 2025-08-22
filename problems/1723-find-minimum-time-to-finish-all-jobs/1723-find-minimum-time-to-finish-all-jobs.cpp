class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1<<n,0);
        for(int b = 1; b <(1<<n); b++){
            for(int i = 0 ; i<n; i++){
                if(b&(1<<i)) sum[b] += jobs[i];
            }
        }
        vector<vector<int>> dp(k+1, vector<int> (1<<n,0));
        for(int b = 1; b< (1<<n) ; b++) dp[1][b] = sum[b];
        for(int i = 2; i<= k; i++){
            for(int b =1;  b< (1<<n) ; b++){
                dp[i][b] = dp[i-1][b];
                for(int subset_of_b = b; subset_of_b > 0; subset_of_b =  (subset_of_b-1)&b ){
                    int cur = max(sum[subset_of_b] , dp[i-1][b - subset_of_b]);
                    dp[i][b] = min(dp[i][b],cur);
                }
            }
        }
        return dp[k][(1<<n)-1];
    }
};