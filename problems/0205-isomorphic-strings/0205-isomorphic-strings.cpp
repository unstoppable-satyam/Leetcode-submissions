class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,char> mp;
        map<char,char> mp2;

        for(int i = 0 ; i<n; i++){  
            if( mp.find(s[i]) != mp.end() ){
                if( mp[s[i]] != t[i] ){
                    cout<<"1  i "<<i<<endl;
                    return false;
                }
            }
            if( mp2.find(t[i]) != mp2.end() ){
                if( mp2[t[i]] != s[i] ){ 
                    cout<<"2  i "<<i<<endl;
                    return false;
                }
            }
            mp[s[i]]  = t[i];
            mp2[ t[i] ] = s[i];
            
        }
        return true;
    }
};