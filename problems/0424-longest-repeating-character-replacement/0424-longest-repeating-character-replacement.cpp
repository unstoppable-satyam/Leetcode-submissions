#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();



class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int>mp;
       int n = s.size();
       int l= 0, r= 0;
       int mx = 0 ;
       for( r= 0 ;r< n; r++){
            mp[s[r]]++;
            int tot = 0;
            int max_frq = 0;
            //cout<<" r "<<r<<endl;
            for(auto it : mp ){
                //cout<<it.first<<" "<<it.second<<endl;
                tot += it.second;
                max_frq = max(max_frq, it.second); 
            }
            tot -= max_frq;
            if( tot > k ){ // need replacement
                mp[s[l]]--;
                l++;
                //cout<<"erase l  r "<<l<<" "<<r<<endl;
            }
            //cout<<"l  r "<<l<<" "<<r<<endl;
            mx = max(mx,r-l+1);
       } 
       return mx;
    }
};