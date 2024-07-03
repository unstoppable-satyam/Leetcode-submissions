class Solution {
private:
 bool isPal(string& str, int s, int e, vector<vector<int>>& isPaldp) {
        if (s >= e) return true; // Correct base case for palindrome check

        if (isPaldp[s][e] != -1) return isPaldp[s][e];

        if (str[s] == str[e]) {
            return isPaldp[s][e] = isPal(str, s + 1, e - 1, isPaldp);
        } else {
            return isPaldp[s][e] = false;
        }
    }

public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<int>> isPaldp(n, vector<int>(n, -1));

        // Precompute the palindrome status
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                isPal(s, i, j, isPaldp);
            }
        }

        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i = n-1; i>= 0; i--){
            int mn = INT_MAX;
            for(int j = i ; j< n; j++){
                if( isPaldp[i][j] ){
                    int part = 1 + dp[j+1];
                    mn = min(mn,part);
                }
                dp[i] = mn;
            }
        }
        return dp[0]-1;    // minus 1 is for the last extra partition added
    }
};