class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(n == 1 ) return arr[0];
        int l = 0,  r = n-1;
        while( l <= r ){
            int mid = (l+r)/2;
            if(arr[l] <= arr[r] ) return arr[l];
            if( arr[mid] >= arr[l] ){
                if( arr[r] >= arr[l] ){
                    r = mid-1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                r = mid;
            }
        }
        return -1;
    }
};