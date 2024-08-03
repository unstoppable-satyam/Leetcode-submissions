class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int l=  0, r = m-1 , u = 0 , d = n-1;
        int cnt = 0;
        cout<<arr[0][0];
        vector<int> ret;
        while( l <= r && u <= d ){
            for(int i = l ; i <= r ; i++){
                ret.push_back(arr[u][i]);
            }
            for(int j = u+1; j<= d-1;  j++){
                ret.push_back(arr[j][r]);
            }
            if( u !=  d ){
                for(int i = r ; i>= l ; i--){
                    ret.push_back(arr[d][i]);
                }
            }
            if(l != r ){
                for(int j = d-1 ; j >= u+1 ;j--){
                    ret.push_back(arr[j][l]);
                }
            }
            l++; r--; u++;d--;
        }
        return ret;
    }
};