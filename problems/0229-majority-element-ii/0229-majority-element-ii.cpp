class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1 ) return nums;
        if(nums.size() == 2 ){
            if(nums[0] == nums[1]) return {nums[0]};
            else return nums;
        }
        int n = nums.size();
        int fs = nums[0]; int se = nums[1];
        int fsf = 2, sef = 2;
        for(int i= 2 ; i<n; i++){
            if(nums[i] == fs ){
                fsf += 2;
            }
            if(nums[i] == se){
                sef += 2;
            }
            if(nums[i] != fs){
                fsf--;
                if(fsf <= 0 ){
                    fs = nums[i];
                    fsf = 2;
                }
            } 
            if(nums[i] != se){
                sef--;
                if ( sef <= 0 ){
                    se = nums[i];
                    sef = 2;
                }
            }
        }
        int cnt_fs = 0;
        int cnt_se = 0;
        for(int i = 0; i< n; i++){
            if(nums[i] == fs) cnt_fs++;
            if(nums[i] == se) cnt_se++;
        }
        vector<int> ret;
        if(cnt_fs > (n/3) ) ret.push_back(fs);
        if(cnt_se > (n/3) && se != fs ) ret.push_back(se);
        return ret;
    }
};