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

    vector<int> next_greater(vector<int> &nums){
        int n = nums.size();
        vector<int> nxg(n,n);
        stack<int> st;
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                nxg[i] = st.top();
            }
            st.push(i);
        }
        return nxg;
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
    vector<int> prev_greater_equal(vector<int>  &nums) {
        int n = nums.size();
        vector<int> prge(n,-1);
        stack<int> st;
    
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                prge[i] = st.top();
            }
            st.push(i);
        }
        return prge;
    }

public:
    long long subArrayRanges(vector<int>& arr) {
        // jitne me max hoga ,utne me add hua hoga
        // jitne me min hoga ,utne me subtract hua hoga 
        int n = arr.size();
        vector<int> nxs =  next_smaller(arr);
        vector<int> prse = prev_smaller_equal(arr);
        vector<int> nxg =  next_greater(arr);
        vector<int> prge = prev_greater_equal(arr);
        // for(auto it : nxs ){
        //     cout<<it <<" ";
        // }
        // cout<<endl;
        // for(auto it : prse ){
        //     cout<<it <<" ";
        // }
        // cout<<endl;
        long long ans = 0;
        for(int i = 0 ; i< n; i++){
            int left = i - prge[i];
            int right =  nxg[i] - i;
            ans  = (ans + 1LL*left*right*arr[i]);
        }
        for(int i = 0 ; i< n; i++){
            int left = i - prse[i];
            int right =  nxs[i] - i;
            ans  = (ans - 1LL*left*right*arr[i]);
        }
        return ans;
    }
};