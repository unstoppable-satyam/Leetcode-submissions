class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2]; //(n/2 will take the right side median element when n is even)
        for(int i = 0 ;  i< n; i++){
            ans += abs(nums[i] -  median); // adding the deviation of each element from optimal resultant value
        }
        return ans;
    }
};