class Solution {
public:
    vector<vector<int>> ret;
private:
    void solve(int node, int parent,int &timer, vector<int> &vis, vector<int> &low, 
    vector<int> adj[] ){
        vis[node] = low[node] = timer++;
        for(auto it : adj[node] ){
            if( it == parent ){
                continue;
            }
            if(!vis[it]){
                solve(it, node,timer, vis,low,adj);
                if (low[it] > vis[node]) { // Check if it's a critical connection
                    ret.push_back({node, it});
                }
                low[node] = min(low[node], low[it] );   // just updating the lowest time of insertion
            }
            else{
                low[node] = min(low[node], vis[it]);    //// just updating the lowest time of insertion
            }
        }
        return;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i= 0; i< connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> low(n, n+1);
        int timer = 1;
        solve(0,-1,timer,vis,low,adj);
        return ret;
    }
};