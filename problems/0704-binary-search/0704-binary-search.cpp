class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n-1;
        while(r-l > 1 ){
            int mid = (l+r)/2;
            if(nums[mid] < target){
                l = mid+1;
            }
            else if( nums[mid] > target){
                r = mid-1;
            }
            else{
                return mid;
            }
        }
        if(nums[l] == target) return l;
        if(nums[r] == target ) return r;
        return -1;
    }
};