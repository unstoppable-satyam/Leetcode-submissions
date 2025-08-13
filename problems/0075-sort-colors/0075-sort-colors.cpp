class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        // 0... low-1 -> contains 0;
        // low... mid-1 -> contains 1;
        // mid... high-> contains unsorted elements;
        // high... n-1 -> contains 2;
        while (mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if( nums[mid] == 2){
                swap(nums[high],nums[mid]);
                //mid++;
                high--;
            }
            else{
                mid++;
            }
        }
        
    }
};