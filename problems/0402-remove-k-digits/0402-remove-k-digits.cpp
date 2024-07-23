class Solution {
private:
    vector<int> next_greater(string &nums){
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
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i = 0; i<n ; i++){
            while(!st.empty() && k>0 && st.top() > num[i] ){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--){
            st.pop();
        }
        if(st.empty() ) return "0";

        string ret="";
        while(!st.empty() ){
            ret.push_back(st.top());
            st.pop();
        }
        while(ret.size() != 0 && ret.back() == '0' ){
            ret.pop_back();
        }
        if(ret.size()  == 0 ) return "0";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};