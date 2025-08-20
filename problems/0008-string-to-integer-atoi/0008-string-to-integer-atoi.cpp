class Solution {

public:
    bool isDigit(char ch){
        if(ch <= '9' && ch >= '0') return true;
        else return false;
    }
    void clean(int i,int n,string &temp,string &s,bool &found,bool sign_found, bool &positive){
        if(i == n){
            return;
        }
        if(found || sign_found){
            if( !isDigit(s[i]) ){
                return;
            }
            else{
                temp.push_back(s[i]);
                clean(i+1,n,temp,s,found,sign_found,positive);
            }
        }
        else{
            if(s[i] == ' '){
                clean(i+1,n,temp,s,found,sign_found,positive);
            }
            else if(s[i] == '+'){
                positive = true;
                sign_found = true;
                clean(i+1,n,temp,s,found,sign_found,positive);
            }
            else if(s[i] == '-'){
                positive = false;
                sign_found = true;
                clean(i+1,n,temp,s,found,sign_found,positive);
            }
            else if(isDigit(s[i])){
                found = true;
                temp.push_back(s[i]);
                clean(i+1,n,temp,s,found,sign_found,positive);
            }
            else{
                return;
            }
        }
    }
    int myAtoi(string s) {
        int n = s.size();
        bool positive = true;
        bool found = false;
        bool sign_found = false;
        string temp ="";
        clean(0,n,temp,s,found,sign_found,positive);
        cout<<" temp "<<temp<<endl;
        int sz = temp.size();
        if(sz == 0) return 0;
        int i = 0;
        for(; i< temp.size(); i++){
            if(temp[i] != '0' ){
                break;
            }
        }
        if(i == sz ) i--;
        string temp2 = temp.substr(i,sz-1-i+1);
        cout<<" temp2 "<<temp<<endl;
        if(temp2.size() == 0 ) temp2.push_back('0');
        if(temp2.size() >= 11 ){
            if(positive) return INT_MAX;
            else return INT_MIN;
        }
        long long a = stoll(temp);
        if( positive && a >= (1LL*INT_MAX) ) a = INT_MAX;
        else if( !positive && a >= abs(1LL*INT_MIN) ) a = INT_MIN;
        if(!positive) a = -a;
        return a;
        // for(; i < s.size(); i++){
        //     if(s[i] != ' ' ) continue;
        //     if(s[i] == '-' || s[i]== '+'){
        //         i++;
        //         break;
        //     }
        //     if(isDigit(s[i])){
        //         break;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        
        // if(i > 0 && s[i-1] == '-' ){
        //     positive = false;
        // }
        // if(!isDigit(s[i]) ) return 0;
        // int j = i;
        // while(j < n && isDigit(s[j]) ){
        //     j++;
        // }
        // j--;
        // while(i<n-1 && s[i] == '0' ){
        //     i++;
        // }
        
        // string temp= "0";
        // if(j <= i ) temp = "0";
        // else temp = s.substr(i,j-i+1);
        // cout<<positive<<endl;
        // cout<<temp;
        // a = stoll(temp);
        // if( positive && a >= (1LL*INT_MAX) ) a = INT_MAX;
        // else if( !positive && a >= abs(1LL*INT_MIN) ) a = INT_MIN;
        // if(!positive) a = -a;
        return a;
    }
};