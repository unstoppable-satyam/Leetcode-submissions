class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n = nums.size();
        int a,b;
        for(int i = 0;i<n; i++){
            if(mp[target-nums[i]] > 0 ){
                a = mp[target-nums[i]] - 1;
                b = i;
            }
            mp[nums[i]] = i+1;
        }
        return {a,b};
    }
};