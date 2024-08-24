class Solution {
public:
    int superEggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int> (k+1,0));
        for(int  i = 1 ; i<= n ; i++){
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(int j = 1 ; j<=k ; j++){
            dp[1][j] = j;
        }
        for(int i = 2;  i <= n ; i++){
            for(int j = 2 ; j<= k; j++){
                // int mn = INT_MAX;
                int low = 1 , high = j;
                int mid = (low+high)/2;
                while(high - low > 1 ){
                    int op1 =  dp[i-1][mid-1];
                    int op2 =  dp[i][j-mid];
                    if( op1 < op2 ){
                        low = mid;
                    }
                    else if( op1 > op2 ){
                        high = mid;
                    }
                    else{
                        low = mid;
                        high = mid;
                        break;
                    }
                    mid = (low+high)/2;
                }
                // for(int x = 1 ; x <= j; x++){
                //     mn = min( mn , max( dp[i-1][x-1], dp[i][j-x]));
                // }
                dp[i][j] = 1 + min( max(dp[i-1][low-1], dp[i][j-low]) ,  max( dp[i-1][high-1] , dp[i][j-high]));
            }
        }
        return dp[n][k];
    }
};