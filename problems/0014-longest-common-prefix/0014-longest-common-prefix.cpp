class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ret = strs[0];
        for(int i = 1; i< n ; i++){
            int j = 0;
            for(j = 0 ; j < min(strs[i].size() , ret.size()) ; j++){
                if( ret[j] !=  strs[i][j] ){
                    break;
                }
            }
            ret = ret.substr(0, j);
        }
        return ret;
    }
};