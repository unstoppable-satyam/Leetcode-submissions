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
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l= 0 , r = n-1;
        cout<<" l "<<l<<" r "<<r<<endl;
        while( l <= r ) {
            int mid = (l+r)/2;
            if( nums[mid] == target ) return true;
            if (nums[l] == nums[mid] || nums[mid] == nums[r]) {
                if(nums[l] == nums[mid] ) l++;
                if(nums[r] == nums[mid] ) r--;
                continue;
            }
            if( nums[mid] >=  nums[l] ){
                if(nums[mid] >= target && target >= nums[l] ){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
                cout<<"if l "<<l<<" r "<<r<<endl;
            }
            else{
                if( nums[mid] <= target && target <= nums[r]  ){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
                cout<<"else l "<<l<<" r "<<r<<endl;
            }
        }
        return false;
    }
};