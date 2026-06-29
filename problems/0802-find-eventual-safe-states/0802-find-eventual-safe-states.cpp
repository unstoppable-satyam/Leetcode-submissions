class Solution {
public:
    vector<int> topoSort(int V, vector<int>adj[]) {
        vector<int> res;
        vector<int> InDeg(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                InDeg[it]++;
            }
        }

        queue<int> q;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int ele = q.front();
                res.push_back(ele);
                q.pop();
                for (auto it : adj[ele]) {
                    InDeg[it]--;
                    if (InDeg[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }
        return res;
    }

    void dfs(int node, vector<int> &vis, vector<int> &pathVis,vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if( vis[it] == 0 ){
                dfs(it,vis,pathVis,adj);
            }
            else if( pathVis[it] == 1 ){
                vis[it] = -1;
            }
            
            if(vis[it] == -1 ){
                vis[node] = -1;
            }
        }
        pathVis[node] = 0;
        //if(vis[node] == -1)
    }
   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[10004];
        for(int i = 0 ; i< V; i++){
            for(auto it: graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i= 0 ; i<V; i++){
            if(!vis[i]) dfs(i,vis,pathVis,adj);
        }
        vector<int> ret;
        for(int i =0 ; i<V; i++){
            if(vis[i] == 1 ){
                ret.push_back(i);
            }
        }
        sort(ret.begin(),ret.end());
        return ret;






        // vector<int> adj[V];
        // for(int i = 0 ; i< V; i++){
        //     for(auto it: graph[i]){
        //         adj[it].push_back(i);
        //     }
        // }
        // vector<int> ts = topoSort(V,adj);
        // sort(ts.begin(),ts.end());
        // return ts;
    }
};