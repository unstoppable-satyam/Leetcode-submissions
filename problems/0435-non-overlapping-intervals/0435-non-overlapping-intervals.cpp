// bool cmp(pair<int,int> a, pair<int,int> b){
//     if(a.first == b.first ) return a.second<b.second;
//     else{
//         return a.first < b.first;
//     }
    
// }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> v(n);  // {end,start}
        for(int i= 0; i< n ; i++){
            v[i] = {intervals[i][1],intervals[i][0]};
        }
        sort(v.begin(),v.end());
        int cnt =1;
        int end_time = v[0].first;
        for(int i= 1;i<n; i++){
            if(v[i].second >= end_time ){  // start time of latter is after the end time
                cnt++;
                end_time = v[i].first;
            }
        }
        return n-cnt;
    }
};