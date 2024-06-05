#include<bits/stdc++.h>
class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> answer(m,vector<int> (n,0));
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0 ){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int x = p.first.first;
            int y = p.first.second;
            int steps = p.second;
            answer[x][y] = steps;
            for(int i=0; i<4 ; i++){
                int nx= x + dx[i];
                int ny= y + dy[i];
                if(nx>=0 && nx <m && ny >=0 && ny<n ){
                    if(!vis[nx][ny]){
                        vis[nx][ny] =1;
                        q.push({{nx,ny},steps+1});
                    }
                }
            }
        }
        return answer;
    }
};