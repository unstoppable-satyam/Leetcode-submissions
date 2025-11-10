class Solution {
const int INF = 1000000000;
public:
    // int solve(int i, int j, vector<int> &cuts,map<pair<int,int> , int> &dp ){
    //     if( dp.find({i,j}) != dp.end() ) return dp[{i,j}];
    //     int mn = INF;
    //     auto it = upper_bound(cuts.begin(),cuts.end(),i);
    //     int lb = it - cuts.begin();
    //     auto it2 = lower_bound(cuts.begin(),cuts.end(),j);
    //     it2--;
    //     int ub = it2 -  cuts.begin();
    //     if( lb > ub ) return dp[{i,j}] = 0;
    //     else{
    //         // cout<<" i "<<i<<" j "<<j<<endl;
    //         // cout<<" lb "<<lb<<" ub "<<ub<<endl;
    //         for(int k = lb; k<= ub; k++){
    //             int val = j-i + solve(i,cuts[k],cuts,dp) + solve(cuts[k],j,cuts,dp);
    //             mn = min(mn, val);
    //         }
    //         //cout<<"mn "<<mn<<endl;
    //         return dp[{i,j}] = mn;
    //     }
    // }

    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp ){
        int mn = INF;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(i+1 >= j){
            return dp[i][j]= 0;
        }
        else{
            for(int k = i+1; k< j; k++){
                int val = cuts[j]-cuts[i] + solve(i,k,cuts,dp) + solve(k,j,cuts,dp);
                mn = min(mn, val);
            }
            //cout<<"mn "<<mn<<endl;
            return  dp[i][j]= mn;
        }
    }


    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>( cuts.size(),-1) );
        return solve(0,cuts.size()-1,cuts,dp);
    }
};