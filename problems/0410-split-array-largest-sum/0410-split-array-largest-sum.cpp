class Solution {
public:
int check(int maxSum, vector<int> &arr, int n, int k){
    int cnt = 1;
    //cout<<" maxpage "<<maxPage<<endl;
    int localSum =  0;
    for(int i =0; i< n; i++){
        if( localSum + arr[i] <= maxSum){
            localSum += arr[i];
        }
        else{
            cnt++;
            localSum = arr[i];
        }
    }
    return (cnt <= k);
}

public:
    int splitArray(vector<int>& nums, int k) {
        // do binary search on largest sum of any subarray 
        int l = *max_element(nums.begin(),nums.end()); // as subarray shouldn't be empty
        int r = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        int mid = (l+r)/2;
        while( r-l >1 ){
            if( check(mid,nums,n,k) ){
                r = mid;
            }
            else{
                l = mid +1;
            }
            mid = (l+r)/2;
        }
        if( check(l,nums,n,k) ){
            return l;
        }
        else if(  check(r,nums,n,k) ){
            return r;
        }
        else{
            return -1;
        }
    }
};