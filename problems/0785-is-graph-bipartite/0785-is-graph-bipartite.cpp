class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i=0; i<n ; i++){
            if(col[i] == -1){
                queue<pair<int,int>> q;
                q.push({i,0});
                col[i] = 0;
                while(!q.empty()){
                    pair<int,int> node = q.front();
                    q.pop();
                    col[node.first] = node.second; 
                    for(auto it : graph[node.first]){
                        if(col[it] == -1 ){
                            q.push({it,!col[node.first]});
                        }
                        else if(col[it] == col[node.first]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};