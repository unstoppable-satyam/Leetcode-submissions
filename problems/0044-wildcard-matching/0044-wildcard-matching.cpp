class Solution {
// bool solve(int i, int j, string &s, string &t,vector<vector<int>> &dp ){
//     if( i < 0 && j <0  ){
//         return true; 
//     }
//     if (i < 0) {
//         while (j >= 0 && t[j] == '*') {
//             j--;
//         }
//         return j < 0;
//     }
//     if( j<0 ){
//         return false;
//     }
//     if( dp[i][j] != -1 ) return (bool) dp[i][j];
//     if( s[i] == t[j] || t[j] == '?'){
//         return dp[i][j] = solve(i-1,j-1,s,t,dp);
//     }
//     else if( t[j] == '*' ){
//         return dp[i][j] =  ( solve(i-1, j, s,t,dp) || solve(i,j-1,s,t,dp));
//     }
//     else{
//         return false;
//     }
// }

bool allStar(string &t,int j){
    while(j>0 ){
        if(t[j-1] != '*' ) return false;
        j--;
    }
    return true;
}


public:
    bool isMatch(string s, string t) {
        if( t == "*" ) return true;
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1 , vector<int> (m+1,0));
        dp[0][0] = 1;
        for(int j = 1; j<= m; j++){
            dp[0][j] = allStar(t,j);
        }

        for(int i = 1; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if( s[i-1] == t[j-1] || t[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if( t[j-1] == '*' ){
                    dp[i][j] =  ( dp[i-1][j] ||  dp[i][j-1]);
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};