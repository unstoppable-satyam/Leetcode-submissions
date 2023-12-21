auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
     bool wordPattern(string pattern, string s) {
        vector<string> hs(26,"");
        map<string,char> mp;
        int n= s.length();
        int m=pattern.length();
        bool exists= false;
        int space_cnt =0;
        for(int i = 0 ; i< n ; i++){
            if(s[i]==' ') space_cnt++;
        }
        //cout<<" space_cnt "<<space_cnt<<" m "<<m<<endl;

        if( m != (space_cnt+1)){
            return false;
        }
        else{
            int j =0;
            int str_cnt =0;
            for (int i = 0; i <m; i++)
            {   
                string temp ="";
                while(s[j] != ' ' && j<n){
                    temp.push_back(s[j]);
                    j++;
                }
                j++;
                //cout<<" temp "<<temp<<endl;
                if(hs[pattern[i]-'a'] == ""){
                    if( mp.find(temp) == mp.end()){
                        hs[pattern[i]-'a'] = temp;
                        mp[temp] = pattern[i];
                    }
                    else{
                        exists = true;
                        break;
                    }       
                }
                else{
                    if((hs[pattern[i]-'a'] != temp) || (mp[temp] != pattern[i])){
                        exists = true;
                        break;
                    }
                    else{
                        continue;
                    }
                }
            }
            return !exists;}
        }    
    
};