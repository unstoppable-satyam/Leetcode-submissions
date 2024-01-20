class Solution {
public:
    unordered_map<int,string> mp;
    Solution() {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }
    vector<string> ans;
    void make(string s,int i,string temp){
        if(i >= s.size()){
            ans.push_back(temp);
            return;
        }
        int ch = s[i] -'0';
        string mapp = mp[ch];
        for(int j = 0; j<mapp.size() ;j++){
            temp.push_back(mapp[j]);
            make(s,i+1,temp);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if( digits.empty()) return ans;
        string temp;
        make(digits,0,temp);
        return ans;
    }
};