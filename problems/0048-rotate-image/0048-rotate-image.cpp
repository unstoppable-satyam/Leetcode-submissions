class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int bd = ceil(n/2.0);
        for(int i =0; i< bd; i++){
            for(int j=0; j< bd; j++){
                if(n%2 != 0 && j == bd-1 ) continue;
                vector<int> temp(4);
                temp[0] = matrix[i][j]; temp[1] = matrix[j][n-1-i];
                temp[2] = matrix[n-1-i][n-1-j]; temp[3] = matrix[n-1-j][i];
                matrix[i][j] = temp[3];
                matrix[j][n-1-i] = temp[0];
                matrix[n-1-i][n-1-j] = temp[1];
                matrix[n-1-j][i] = temp[2];
            }
        }
    }
};