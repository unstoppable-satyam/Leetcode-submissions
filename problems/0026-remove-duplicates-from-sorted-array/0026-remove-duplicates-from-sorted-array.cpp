class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n ){
            while(j+1 < n && nums[j+1] == nums[i] ){
                j++;
            }
            j++;
            if(j == n ) break;
            i++;
            if(i == n ) break;
            swap( nums[i],nums[j]);
            cnt++;
            
        }
        return cnt;
    }
};