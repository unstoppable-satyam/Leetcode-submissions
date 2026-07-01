class Solution {
public:
    void solve(int op, int cl, int n, string &s , vector<string> &ret){
        if( (op + cl) == (2*n) ){
            ret.push_back(s);
            return;
        }

        if( op > cl ){
            s.push_back(')');
            solve(op,cl+1,n,s,ret);
            s.pop_back();
        }
        if( op < n ){
            s.push_back('(');
            solve(op+1,cl,n,s,ret);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ret;
        solve(0,0,n,s,ret);
        return ret;
    }
};