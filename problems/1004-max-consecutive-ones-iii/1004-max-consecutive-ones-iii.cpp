class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r = 0;
        int gb = 0;
        int cnt_one = 0;
        int cnt_zero = 0;
        for(; r<n; r++){
            if(nums[r] == 1 ){
                cnt_one++;
                gb = max(gb,r-l+1);
            }
            else{
                cnt_zero++;
                if(cnt_zero <= k){
                    gb = max(gb,r-l+1);
                }
                else{
                    while(l <= r && cnt_zero > k ){
                        if(nums[l] == 1 ){
                            cnt_one--;
                        }
                        else{
                            cnt_zero--;
                        }
                        l++;
                    }
                }
            }
        }
        return gb;
    }
};