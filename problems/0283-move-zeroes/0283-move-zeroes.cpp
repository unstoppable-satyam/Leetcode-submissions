class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i= 0;
        int cnt_z = 0;
        int n = nums.size();
        while(i< n){
            if(nums[i] == 0){
                cnt_z++;
                i++;
            }
            else{
                swap(nums[i],nums[i-cnt_z]);
                //nums[i-cnt_z] = nums[i];
                i++;
            }
        }
        for(int i = n-cnt_z ; i< n; i++){
            nums[i] = 0;
        }
    }
};