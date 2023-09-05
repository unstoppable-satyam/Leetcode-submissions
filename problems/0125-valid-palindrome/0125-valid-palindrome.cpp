class Solution {

private:
    
string toLowerCase(string &res){
    for(int i = 0  ; i< res.length() ; i++){
       if(('A' <= res[i] && res[i] <= 'Z')){
            res[i] = res[i] -'A'+'a';
       }
    }
    return res;
}        
public:

bool isPalindrome(string s) {
        string res;
        for(int i = 0 ; i< s.length() ; i++){
            if( ('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
               res +=s[i];
            }
            else{
                continue;
            }
        }
        toLowerCase(res);
        int start= 0;
        int end = res.length() -1 ;
        while( start<= end){
            if(res[start++] != res[end--]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
};