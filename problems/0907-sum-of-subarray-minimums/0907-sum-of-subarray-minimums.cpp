class Solution {
private:
    vector<int> next_smaller(vector<int> &nums){
        int n = nums.size();
        vector<int> nxs(n,n);
        stack<int> st;
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                nxs[i] = st.top();
            }
            st.push(i);
        }
        return nxs;
    }

    vector<int> prev_smaller_equal(vector<int>  &nums) {
        int n = nums.size();
        vector<int> prse(n,-1);
        stack<int> st;
    
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] > nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                prse[i] = st.top();
            }
            st.push(i);
        }
        return prse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxs =  next_smaller(arr);
        vector<int> prse = prev_smaller_equal(arr);
        // for(auto it : nxs ){
        //     cout<<it <<" ";
        // }
        // cout<<endl;
        // for(auto it : prse ){
        //     cout<<it <<" ";
        // }
        // cout<<endl;
        int mod = 1e9 + 7;
        long long ans = 0;
        for(int i = 0 ; i< n; i++){
            int left = i - prse[i];
            int right =  nxs[i] - i;
            ans  = (ans + 1LL*left*right*arr[i])%mod;
        }
        return ans;
    }
};