class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        //vector<vector<int>> adj[]

        priority_queue< pair<int,pair<int,int>> , 
        vector<pair<int,pair<int,int> >> , greater<pair<int,pair<int,int>>> > pq; //min heap
        pq.push({0, {points[0][0] , points[0][1]} } );  // { wt , { x,y }}

        map<pair<int,int> , int> vis;
        int sum = 0;
        while(!pq.empty() ){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if( vis.find({x,y}) != vis.end() )  continue;
            
            // if(parent != -1 )mst.push_back({node,parent});
            
            vis[{x,y}] = 1;
            sum += wt;
            
            for(int i = 0; i< n; i++){
                int child_x = points[i][0];
                int child_y = points[i][1];
                int edge_weight = abs(x - child_x) + abs(y - child_y);
                if(vis.find({child_x,child_y}) != vis.end()   ) continue;
                pq.push({edge_weight,{child_x,child_y}});
            }
        }
        return sum;
    }
};