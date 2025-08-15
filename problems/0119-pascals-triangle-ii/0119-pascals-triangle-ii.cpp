class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int sz =0;
        int numRows = rowIndex+1;
        vector<int> v(numRows);
        v[0] = 1;
        for(int i = 0; i < numRows ; i++){
            sz++; 
            int last = 1;
            for(int j = 1; j<sz; j++){
                int val = last;
                if(j != sz-1) {
                    val += v[j];
                }
                last = v[j];
                v[j] = val;
            }
        }
        return v;
    }
};