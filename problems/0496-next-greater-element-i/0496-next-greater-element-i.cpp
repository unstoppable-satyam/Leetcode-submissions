class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(int i  = 0 ; i < nums2.size() ; i++){
            mp[nums2[i]] = i;
        }
        int n = nums2.size();
        vector<int> nxg(n,-1);
        stack<int> st;
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums2[st.top()] <= nums2[i] ){
                st.pop();
            }
            if(!st.empty()){
                nxg[i] = st.top();
            }
            st.push(i);
        }

        int q = nums1.size();
        vector<int> ret(q,0);
        for(int i = 0; i< q; i++){
            int num = nums1[i];
            int ind = mp[num];
            int next_gr_ind = nxg[ind];
            if( next_gr_ind == -1 ){
                ret[i] = -1;
            }
            else{
                int next_gr_ele = nums2[next_gr_ind];
                ret[i] = next_gr_ele;
            }
            
        }
        return ret;
    }
};