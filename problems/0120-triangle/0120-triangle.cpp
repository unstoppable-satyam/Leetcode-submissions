class Solution {
public:
    int minimumTotal(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = n;
        vector<int> prev(m,0);
        vector<int> cur(m,0);
        for(int i = 0; i<n; i++){
            for( int j= 0;j<=i; j++ ){
                if(i == 0 &&  j == 0 ){
                    cur[j] = grid[i][j];
                    continue;
                }
                int up = INT_MAX;
                int up_left = INT_MAX;
                if( i > 0 && j != i ) up = prev[j];
                if(j > 0 && j != 0) up_left = prev[j-1];
                cur[j] = min(up,up_left) + grid[i][j];
            }
            for(int j= 0; j<m; j++){
                prev[j] = cur[j];
            }
        }
        auto it = *min_element(cur.begin(),cur.end());
        return it;
    }
};