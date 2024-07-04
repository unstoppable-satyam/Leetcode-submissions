class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int len;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int i= 1; i<= n ; i++){
            for(int j= 1; j<= m ; j++){
                if(s1[i-1] == s2[j-1] ){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],  dp[i][j-1]);
                }        
            }
        }
    
        len = n+m- dp[n][m];
        string ret = "";
        for(int i= 0; i< len ; i++){
            ret +='$';
        }   // initialise a string with dummy variable to store the supersequence

        int i =n, j = m;
        while( i>0 && j>0){
            if(s1[i-1] == s2[j-1] ){
                ret[len-1] = s1[i-1]; 
                i--; j--;
                len--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ret[len-1] = s1[i-1];
                i--;
                len--;
            }
            else{
                ret[len-1] = s2[j-1];
                j--;
                len--;
            }
        }
        while( j>0 ){
            ret[len-1] = s2[j-1];
            j--; len--;
        }
        while( i>0 ){
            ret[len-1] = s1[i-1];
            i--; len--;
        }
        return ret;
    }
};