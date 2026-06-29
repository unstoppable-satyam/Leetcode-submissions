class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size() ,  m = mat[0].size();
        int l =0, r = n*m-1;
        int mid,row,col; 
        while( (r-l) > 1 ){
            mid =(r+l)/2;
            row = mid/m;
            col = mid%m;
            if( mat[row][col] < target){
                l = mid+1;
            }
            else if( (mat[row][col] > target) ){
                r = mid-1;
            }
            else{
                return true;
            }
        }
        if( mat[l/m][l%m] == target ) return true;
        if( mat[r/m][r%m] == target ) return true;
        return false;
    }
};