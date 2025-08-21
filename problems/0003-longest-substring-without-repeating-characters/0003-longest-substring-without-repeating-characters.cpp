class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> last_occ(256,-1);
        int gb = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            if(last_occ[s[i]] != -1){
                j = max( last_occ[s[i]] + 1 , j);
                last_occ[s[i]] = i;
                gb = max(gb,i-j+1);
            }
            else{
                gb = max(gb,i-j+1);
                last_occ[s[i]] = i;
            }
        }
        return gb;
    }
};