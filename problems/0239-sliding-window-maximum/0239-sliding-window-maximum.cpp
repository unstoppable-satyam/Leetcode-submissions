class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // store indices. { monotonically decr , push in back}
        vector<int> ret;
        for(int i= 0; i<n; i++){

            // empty the left side to get space for the current window
            while( !(dq.empty()) && dq.front() <= (i-k) ){
                dq.pop_front();
            }

            while( !(dq.empty()) && nums[dq.back()] <= nums[i]   ){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1 ){
                ret.push_back(nums[dq.front()]);
            }
        }
        return ret;
    }
};