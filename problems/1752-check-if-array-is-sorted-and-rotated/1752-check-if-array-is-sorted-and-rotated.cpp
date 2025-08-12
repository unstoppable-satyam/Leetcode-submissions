class Solution {
public:
    bool check(vector<int>& nums) {
        int dec = 0;
        for(int i= 0; i< nums.size()-1 ; i++){
            if(nums[i+1] < nums[i] ) dec++;
        }
        if(dec == 0) return true;
        if(dec == 1 && nums[0] >= nums[nums.size()-1] ) return true;
        return false;
    }
};