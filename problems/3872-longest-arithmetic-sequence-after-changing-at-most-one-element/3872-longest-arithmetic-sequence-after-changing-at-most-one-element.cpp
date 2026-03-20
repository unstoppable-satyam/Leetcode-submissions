class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n-1);
        for(int i = 1; i<n; i++){
            diff[i-1] = nums[i] - nums[i-1];
        }
        int ans = 2;
        int mx = 2;
        int cur = 1;
        for(int i =1; i<n-1; i++){
            if(diff[i] == diff[i-1]){
                cur++;
                mx = max(mx,cur+2);
            }
            else{
                cur = 1;
                mx = max(mx,cur+2);
            }
        }
        ans = min(mx,n);

        vector<int> lf(n-1,2),rt(n-1,2);
        int seq = 2;
        for(int i = 1; i<n-1; i++){
            if(diff[i] == diff[i-1]){
                seq++;
            }
            else{
                seq = 2;
            }
            lf[i] = seq;
        }
        seq = 2;
        for(int i = n-3;i >=0; i--){
            if(diff[i] == diff[i+1]){
                seq++;
            }
            else{
                seq = 2;
            }
            rt[i] = seq;
        }
        for(int i =1 ; i<= n-3; i++){
            if(diff[i] + diff[i+1] == 2*diff[i-1]){
                int cur_len = lf[i-1];
                cur_len += 2;
                if(i+2 < n-1 && diff[i+2] == diff[i-1] ) cur_len += rt[i+2]-1;
                ans = max(ans, cur_len);
            }
        }
        for(int i = n-3; i>=1 ; i--){
            if(diff[i] + diff[i-1] == 2*diff[i+1]){
                int cur_len = rt[i+1];
                cur_len += 2;
                if( i-2 >= 0 && diff[i-2] == diff[i+1] ) cur_len += lf[i-2]-1;
                ans = max(ans, cur_len);
            }
        }
        return ans;
    }
};