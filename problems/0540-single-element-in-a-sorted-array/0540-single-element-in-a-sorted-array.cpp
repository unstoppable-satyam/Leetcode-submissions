class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1 ) return arr[0];

        int l = 0, r = n-1;

        while( l <= r ){
            int mid = (l+r)/2;
            if( mid+1 <n && arr[mid] == arr[mid+1] ){
                if( mid%2 == 0 ){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else if(mid -1 >= 0 && arr[mid] == arr[mid-1]  ){
                if( mid%2 == 0 ){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                return arr[mid];
            }
        }
        return -1;
    }
};