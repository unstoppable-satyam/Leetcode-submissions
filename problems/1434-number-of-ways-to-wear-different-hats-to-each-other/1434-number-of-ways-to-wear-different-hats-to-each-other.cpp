class Solution {
public:
    int solve(int i, int n, int man_occ,vector<vector<int>> &poss_man, vector<vector<int>> &dp ){
        if( man_occ == ((1<<n)-1) ) return 1;
        if(i == 41 ) return 0;
        if( dp[i][man_occ] != -1 ) return dp[i][man_occ];
        int ways = solve(i+1,n,man_occ,poss_man,dp);
        for(auto cur_man: poss_man[i]){
            if((man_occ&(1<<cur_man))) continue;
            ways = (ways+ solve(i+1,n, man_occ|(1<<cur_man), poss_man,dp ))%1000000007;
        }
        return dp[i][man_occ] = ways;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> poss_man(41);
        for(int i = 0; i<n ; i++){
            for(auto it: hats[i]){
                poss_man[it].push_back(i);
            }
        }
        vector<vector<int>> dp(41, vector<int>(1<<n,-1));
        int ans = solve(1,n,0,poss_man,dp);
        return ans;
    }
};