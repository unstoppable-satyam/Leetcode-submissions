typedef long long ll;
class Solution {
public:
    bool allThreeExists(vector<int> &hs ){
        for(int i = 0; i<3; i++){
            if( hs[i] == 0 ) return false;
        }
        return true;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> hs(n,0);

        ll notAllThree_cnt = 0;
        int l =0, r = 0;
        while( r < n){
            hs[s[r] - 'a']++;
            
            while(  allThreeExists(hs) ){
                hs[s[l]-'a']--;
                l++;
            }
            notAllThree_cnt += (r-l+1);
              
            r++;
        }

        ll totalSubstring = (n*1LL*(n+1))/2;        
        return totalSubstring - notAllThree_cnt; 
        
    }
};