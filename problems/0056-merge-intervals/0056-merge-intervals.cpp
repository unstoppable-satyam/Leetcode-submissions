class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st = intervals[0][0];
        int en = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> res;
        for(int i = 1; i<n ; i++){
            if(intervals[i][0] > en ){
                res.push_back({st,en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
            en = max(en,intervals[i][1]);
        }
        res.push_back({st,en});
        return res;
    }
};