typedef long long ll;
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<ll> time(n,LLONG_MAX),ways(n,0);
        time[0] = 0;
        ways[0] = 1;
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
        pq.push({0,0});   //{time to reach that node,node}
        while(!pq.empty() ){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            ll tot_time = it.first;
    
            for(auto el : adj[node] ){
                int adj_node = el.first;
                int edge_time = el.second;
                if( time[adj_node] > time[node] + edge_time ){
                    time[adj_node] = time[node] + edge_time;
                    ways[adj_node] =  ways[node];
                    pq.push({time[adj_node], adj_node});
                }
                else if(time[adj_node] == time[node] + edge_time ){
                    ways[adj_node] =  (ways[adj_node] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};