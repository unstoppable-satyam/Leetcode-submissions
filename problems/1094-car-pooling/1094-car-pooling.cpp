class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        int n = trips.size();
        for(int i = 0 ; i<n ;i++){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }
        int mx = 0 ;
        //int mx_ind = -1;
        int sum = 0 ;
        for(auto it : mp){
            sum += it.second;
            if(sum > mx ){
                //mx_ind = it.first;
                mx = sum;
            }
        }
        return mx <= capacity;
    }
};