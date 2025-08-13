class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mfe = nums[0];
        int mfe_cnt = 1;
        for(int i= 1; i< nums.size(); i++){
            if(nums[i] == mfe){
                mfe_cnt++;
            }
            else{
                mfe_cnt--;
                if(mfe_cnt < 0 ){
                    mfe = nums[i];
                    mfe_cnt = 1;
                }
            }
        }
        return mfe;
    }
};