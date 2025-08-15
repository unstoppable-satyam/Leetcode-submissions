class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int sz =0;
        vector<vector<int> > v(numRows);
        for(int i = 0; i < numRows ; i++){
            sz++; 
            v[i].push_back(1);
            for(int j = 1; j<sz; j++){
                int val = v[i-1][j-1];
                if(j != sz-1) val += v[i-1][j];
                v[i].push_back(val);
            }
        }
        return v;
    }
};