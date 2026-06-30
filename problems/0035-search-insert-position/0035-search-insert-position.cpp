class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while( r-l > 1 ){
            int mid = (l+r)/2;
            if(nums[mid] == target ){
                return mid;
            }
            if(nums[mid] < target ){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        if(target > nums[r] ) return r+1;
        if( target > nums[l] ) return l+1;
        return l;
    }
};