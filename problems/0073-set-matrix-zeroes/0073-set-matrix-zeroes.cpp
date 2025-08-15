class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        set<int> rows, cols;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0 ){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto it: rows){
            int i = it;
            for(int j =0; j<m; j++){
                matrix[i][j] = 0;
            }
        }
        for(auto it: cols){
            int j = it;
            for(int i= 0; i< n; i++){
                matrix[i][j] =0;
            }
        }
    }
};