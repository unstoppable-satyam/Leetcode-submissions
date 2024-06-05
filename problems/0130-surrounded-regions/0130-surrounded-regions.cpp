class Solution {

private:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[i][j]=1;
        int m= board.size();
        int n= board[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!vis[nx][ny] && board[nx][ny] == 'O') {
                    vis[i][j]=1;
                    dfs(nx, ny, board, vis);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O')  dfs(i,j,board,vis);                   
                }
            }
        }
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};