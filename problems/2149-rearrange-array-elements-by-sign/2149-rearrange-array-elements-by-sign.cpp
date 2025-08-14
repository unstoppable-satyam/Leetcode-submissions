class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        int i = 0, j = 0;
        int k = 0;
        while(k<n){
            while(i <n && nums[i] <= 0){
                i++;
            }
            res[k++] = nums[i++];
            while(j < n && nums[j] >= 0 ){
                j++;
            }
            res[k++] = nums[j++];
        }
        return res;
    }
};