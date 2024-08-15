class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pf(n,0);
        pf[0] = nums[0];
        for(int i= 1; i< n; i++){
            pf[i] = pf[i-1] + nums[i];
        }
        int cnt = 0;
        //int l =0, r = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i= 0 ;  i<n; i++){
            int to_find = pf[i] - goal;
            if( to_find >= 0 ){
                cnt += mp[to_find];
            }
            mp[pf[i]]++;
        }
        return cnt;
    }
};