class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        int n = logs.size();
        for(int i = 0 ; i<n ;i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }
        int mx = 0 ;
        int mx_ind = -1;
        int sum = 0 ;
        for(auto it : mp){
            sum += it.second;
            if(sum > mx ){
                mx_ind = it.first;
                mx = sum;
            }
        }
        return mx_ind;
    }
};