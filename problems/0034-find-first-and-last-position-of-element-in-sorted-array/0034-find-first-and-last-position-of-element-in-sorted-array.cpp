class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(),nums.end(),target);
        auto it2 = upper_bound(nums.begin(),nums.end(),target);
        int l = -1;
        int r = -1;
        
        l = it1- nums.begin();
        r = it2 - nums.begin();
        if(l == r ) return {-1,-1};
        return {l,r-1};
    }
};