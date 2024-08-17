class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        // Initialize the first row of dp
        for (int j = 0; j < m; j++) {
            dp[0][j] = points[0][j];
        }
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            // Left to right pass
            long long lcm = dp[i-1][0];
            int ind = 0;
            for (int j = 0; j < m; j++) {
                if (dp[i-1][j] > lcm - (j - ind)) {
                    lcm = dp[i-1][j];
                    ind = j;
                }
                dp[i][j] = max(dp[i][j], lcm + points[i][j] - (j - ind)); 
            }

            // Right to left pass
            lcm = dp[i-1][m-1];
            ind = m-1;
            for (int j = m-1; j >= 0; j--) {
                if (dp[i-1][j] > lcm + (j - ind)) {
                    lcm = dp[i-1][j];
                    ind = j;
                }
                dp[i][j] = max(dp[i][j], lcm + points[i][j] - (ind - j));
            }
        }
        
        // Return the maximum value in the last row of dp
        long long ans = *max_element(dp[n-1].begin(), dp[n-1].end());
        return ans;
    }
};