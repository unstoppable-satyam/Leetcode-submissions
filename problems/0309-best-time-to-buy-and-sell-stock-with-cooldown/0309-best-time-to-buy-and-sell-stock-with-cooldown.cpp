class Solution {
private:
    int solve(int ind,int buy,int cool,int n,vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind >= n ) return 0;
        if(dp[ind][buy][cool] != -1 ) return dp[ind][buy][cool];
        if(buy == 0){
            // buys
            int op1 = 0;
            int op2 = 0;
            if(cool == 0){
                op1 = -prices[ind] + solve(ind+1,!buy,cool,n,prices,dp);
                // not buys
                op2 = solve(ind+1,buy,cool,n,prices,dp);
            }
            else{
                op2 = solve(ind+1,buy,!cool,n,prices,dp);
            }
            return dp[ind][buy][cool] = max(op1,op2);

        }
        else{
            //sells
            int op3 = prices[ind] + solve(ind+1,!buy,!cool,n,prices,dp);
            // not sells
            int op4 = solve(ind+1,buy,cool,n,prices,dp);
            return dp[ind][buy][cool]= max(op3,op4);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (2,-1)));
        //cool == 0 -> can buy 
        //cool == 1 -> can't buy
        return solve(0,0,0,n,prices,dp);
    }
};