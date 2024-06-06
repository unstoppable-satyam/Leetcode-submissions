class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int j= 0 ; j<n ; j++){
            if(grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(grid[m-1][j] == 1){
                q.push({m-1,j});
                vis[m-1][j] = 1;
            }
        }
        for(int i=1; i<m-1 ; i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(grid[i][n-1] == 1){
                q.push({i,n-1});
                vis[i][n-1] = 1;
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){
            pair<int,int> node= q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            vis[x][y] = 1;
            for(int i=0; i<4 ; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] != 1 && grid[nx][ny] == 1){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                } 
            }
        }
        int cnt=0;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n ;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};