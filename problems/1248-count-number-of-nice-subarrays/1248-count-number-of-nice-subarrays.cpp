class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> lt,rt;
        int n  = nums.size();
        int cur = 0;
        for(int i = 0; i<n; i++){
            cur++;
            if(nums[i]%2 == 1 ){
                lt.push_back(cur);
                cur = 0;
            }
        }
        cur = 0;
        for(int i = n-1;i>=0 ; i--){
            cur++;
            if(nums[i]%2 == 1 ){
                rt.push_back(cur);
                cur = 0;
            }
        }

        reverse(rt.begin(),rt.end());

        long long ans = 0;
        int sz = lt.size();
        for(int i= 0;i< sz; i++){
            int j = i+k-1;
            if( j >= sz ) break;
            ans += (lt[i]*rt[j]);
        }
        return ans;
    }
};