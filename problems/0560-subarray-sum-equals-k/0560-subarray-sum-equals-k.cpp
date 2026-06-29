typedef long long ll;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        ll sum = 0;
        map<ll,ll> mp;
        mp[0] = 1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};