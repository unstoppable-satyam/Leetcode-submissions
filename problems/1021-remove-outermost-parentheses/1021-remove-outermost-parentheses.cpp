class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        vector<int> v(n,0);
        int cnt =0;
        for(int i =  0; i < n ; i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
            }
            v[i] = cnt;
        }
        for(int i =  0; i < n ; i++){
            cout<<v[i]<<" ";
        }
        string ans = "";
        for(int i =  1; i < n ; i++){
            if(v[i] == 0 ){
                i++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};