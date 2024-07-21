class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nxg(n,-1);
        stack<int> st;
        for(int i = n-1 ; i>= 0 ; i--){
            st.push(i);
        }
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                nxg[i] = st.top();
            }
            st.push(i);
        }
        vector<int> ret(n,-1);
        for(int i = 0; i< n ; i++){
            if(nxg[i] != -1 ){
                ret[i] = nums[nxg[i]];
            }
            else{
                ret[i] = -1;
            }
        }
        return ret;
    }
};