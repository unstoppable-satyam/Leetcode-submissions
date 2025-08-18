class Solution {
public:
    bool check(int l, int r, int n){
        if( r > l ){
            return (r-l)>1;
        }
        else{
            return ((r-l+n)%n)>1;
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l= 0 , r = n-1;
        while( l <= r ) {
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            
            if( nums[mid] >=  nums[l]){
                if(nums[mid] >= target && target >= nums[l] ){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if( nums[mid] <= target && target <= nums[r]  ){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;

        // int change_ind = n;
        // for(int i = 0; i<n-1; i++){
        //     if(nums[i+1] < nums[i]){
        //         change_ind = i+1;
        //     }
        // }
        // cout<<change_ind<<endl;
        // int k = n - change_ind;
        // cout<<k<<endl;
        // int l = (0-k+n)%n; int r = (n-1-k+n)%n;
        // //cout<<" l "<<l<<" r "<<r<<endl;
        // while( check(l,r,n) ){
        //     int ll = (l+k)%n;
        //     int rr = (r+k)%n;
        //     int mid = (ll+rr)/2;
        //     mid =(mid-k+n)%n;
        //     cout<<"mid "<<mid<<endl;
        //     if(nums[mid] < target){
        //         l = (mid+1)%n;
        //     }
        //     else if(nums[mid] > target){
        //         r = (mid-1+n)%n;
        //     }
        //     else{
        //         return mid;
        //     }
        //     cout<<" l "<<l<<" r "<<r<<endl;
        // }
        // if( nums[l] == target ) return l;
        // else if(nums[r] == target) return r;
        // else return -1;
    }
};