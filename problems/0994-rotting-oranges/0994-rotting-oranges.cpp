class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0;
        queue<pair<int,int>> q; // { i,j};
        for(int i= 0 ; i< n ; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] ==1 || grid[i][j] == 2 ){
                    tot++;
                }
                if(grid[i][j] == 2 ){
                    q.push({i,j});
                }
            }
        }
        int di[4] = {1 ,-1 , 0 , 0};
        int dj[4] = {0 , 0 , 1 ,-1};
        int cnt = 0;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            cnt += sz;
            time++;
            for(int ele =  0; ele < sz; ele++){
                auto node  = q.front();
                int i= node.first;
                int j= node.second;  
                q.pop();
                for(int k = 0; k<4 ; k++){
                    int ni = i +  di[k];
                    int nj = j +  dj[k];
                    if( ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] != 1 ) continue;
                    grid[ni][nj] = 2;
                    q.push({ni,nj});
                }
            }
        }
        if( tot != cnt ) return -1;
        else return time == 0 ? 0 : time-1;
    }
};