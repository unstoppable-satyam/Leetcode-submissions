class Solution {
private:
    int solve(int l , int r, int count , vector<int> &boxes, vector<vector<vector<int>>> &dp ){
        if(l>r ) return 0;

        if( dp[l][r][count] != -1 ) return dp[l][r][count];
        int ans = (count+1)*(count+1) + solve(l+1,r,0,boxes,dp);
        for(int i =l+1 ; i<= r; i++){
            if(boxes[i] == boxes[l] ){
                ans = max(ans,solve(i,r,count+1,boxes,dp) + solve(l+1,i-1,0,boxes,dp));
            }
        }
        return dp[l][r][count] = ans;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        int  n= boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n,-1)));
        return solve(0,n-1,0,boxes,dp);
    }
};