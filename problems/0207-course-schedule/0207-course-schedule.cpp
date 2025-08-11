class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[2001];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ts = topoSort(numCourses,adj);
        if(ts.size() < numCourses ) return false;
        return true;
    }
};