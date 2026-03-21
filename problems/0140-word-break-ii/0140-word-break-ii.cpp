class Solution {
public:
    vector<string > ret;
    void solve(int i, string &s,vector<string> &v, unordered_set<string> &dict ){
        if( i < 0 ){
            string ans;
            int sz = v.size();
            if(sz == 0 ) return;
            ans += v[sz-1];
            for(int j = sz-2; j>=0; j--){
                ans += ' ';
                ans += v[j];
            } 
            ret.push_back(ans);
        }
        for(int j = i; j>= 0; j--){
            string substring = s.substr(j,i-j+1);
            if(dict.find(substring) != dict.end() ) {
                v.push_back(substring);
                solve(j-1,s,v,dict);
                v.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> v;
        solve(n-1,s,v,dict);
        return ret;
    }
};