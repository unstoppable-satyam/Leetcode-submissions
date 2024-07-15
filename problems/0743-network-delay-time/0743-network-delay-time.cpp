class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int v, int s) {
        vector<vector<int>> adj[v+1];
        for(int i = 0; i< times.size() ; i++ ){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> time(v+1,INT_MAX);
        time[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,s}); //  { dist till node, node}
        
        vector<int> vis(v+1,0);
        while( !pq.empty() ){
            auto it = pq.top();
            int node = it.second;
            int weight = it.first;
            pq.pop();
            if( vis[node] ) continue;
            vis[node] = 1;

            for(auto adj_el : adj[node] ){
                int adj_node = adj_el[0];
                int edge_weight = adj_el[1];
                
                if(vis[adj_node] ) continue;
                if(time[adj_node] > time[node] + edge_weight ){
                    time[adj_node] = time[node] + edge_weight;
                    pq.push({time[adj_node], adj_node});
                }
            }
        }
        int mx = 0;
        for(int i =1 ; i<= v; i++){
            if(time[i] == INT_MAX ) return -1;
            mx = max(mx,time[i]);
        }
        return mx;
    }
};