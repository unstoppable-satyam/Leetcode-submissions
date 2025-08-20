class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0);
        vector<int> cur(m,0);
        for(int i = 0; i<n; i++){
            for(int j= 0;j<m; j++){
                if(i == 0 &&  j == 0 ){
                    cur[j] = grid[i][j];
                    continue;
                }
                int up = INT_MAX;
                int left = INT_MAX;
                if(i > 0 ) up = prev[j];
                if(j > 0 ) left = cur[j-1];
                cur[j] = min(up,left) + grid[i][j];
            }
            for(int j= 0; j<m; j++){
                prev[j] = cur[j];
            }
        }
        return cur[m-1];
    }
};